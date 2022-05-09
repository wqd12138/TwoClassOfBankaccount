#include<iostream>
#include<fstream>
#include<ctime>
#include"brass.h"

using std::ios;
using std::cout;
using std::string;
using std::endl;
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f,precis p);
Brass::Brass(const std::string & s,long an ,double bal )
{
	fullName = s;
	accNum = an;
	balance = bal;
}
void Brass::Deposit(double amt)
{
	if (amt<0.0)
		cout<<"Negative deposit not allowed;"
			<<"deposit is canelled."<<endl;
	balance += amt;
	RecordLog(amt,true);
}
double Brass::Balance() const
{
	return balance;
}
void Brass::WithDraw(double amt)
{
	//set up ###.##格式
	format initialState = setFormat();
	precis prec = cout.precision(2);
	if (amt<0.0)
		cout<<"Withdrawal amout must be positive;"<<"withdrawal canceled."<<endl;
	else if (amt<=balance)
		balance -= amt;
	else
		cout<<"Withdrawal amout of $"<<amt<<"exceeds balance."<<endl<<"Withdrawal cancelled."<<endl;
	restore(initialState,prec);
	RecordLog(amt,false);
}
void Brass::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout<<"Cilent: "<<fullName<<endl;
	cout<<"Account Number: "<<accNum<<endl;
	cout<<"Balance: $"<<balance<<endl;
	restore(initialState,prec);
}
void Brass::RecordLog(double dnum,bool isDeposit)
{
	std::ofstream ofs;
	ofs.open("./BankLog.txt",ios::out|ios::app);//相对路径
	if (!ofs.is_open())
		cout<<"failed to open BankLog"<<endl;
	// 基于当前系统的当前日期/时间
	time_t now = time(0);
	// 把 now 转换为字符串形式
	char* dt = ctime(&now);
	ofs<<dt;
	if (isDeposit)
	{
		ofs<<fullName<<" 的账户"<<accNum<<"余额为： $"<<Balance()<<endl;
		ofs<<fullName<<" 的账户"<<accNum<<"存入 $"<<dnum<<endl;
		ofs<<fullName<<" 的账户"<<accNum<<"余额为： $"<<Balance()<<endl;
	}
	else
	{
		ofs<<fullName<<" 的账户"<<accNum<<"余额为： $"<<Balance()<<endl;
		ofs<<fullName<<" 的账户"<<accNum<<"支出 $"<<dnum<<endl;
		ofs<<fullName<<" 的账户"<<accNum<<"余额为： $"<<Balance()<<endl;
	}
	ofs.close();
}
BrassPlus::BrassPlus(const std::string &s,long an ,double bal ,double m1,double r ):Brass(s,an,bal)
{
	maxLoan = m1;
	owesBank = 0.0;
	rate = r;
}
BrassPlus::BrassPlus(const Brass &ba,double m1,double r):Brass(ba)
{
	maxLoan = m1;
	owesBank = 0.0;
	rate = r;
}
void BrassPlus::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	Brass::ViewAcct();
	cout<<"Maximum loan: $"<<maxLoan<<endl;
	cout<<"owed to bank: $"<<owesBank<<endl;
	cout.precision(3);
	cout<<"Loan rate: "<<100*rate<<"%"<<endl;
	restore(initialState,prec);

}
void BrassPlus::WithDraw(double amt) 
{
	//set up ###.##格式
	format initialState = setFormat();
	precis prec = cout.precision(2);
	double bal =Balance();
	if (amt<=bal)
		Brass::WithDraw(amt);
	else if (amt<=bal + maxLoan -owesBank)
	{
		double advance =amt -bal;
		owesBank+=advance*(1.0+rate);
		cout<<"Bank advance: $"<<advance<<endl;
		cout<<"Finance charge: $"<<advance*rate<<endl;
		Deposit(advance);
		Brass::WithDraw(amt);
	}
	else
		cout<<"Credit limit ecxeeded.Transaction cancelled."<<endl;
	restore(initialState,prec);
}
format setFormat()
{
	return cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
}
void restore(format f,precis p)
{
	cout.setf(f,std::ios_base::floatfield);
	cout.precision(p);
}