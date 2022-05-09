#include<iostream>
#include"brass.h"
//#include"usebrass2.cpp"
extern int iInusebrass2 =1;
int main()
{
	using namespace std;
	Brass Piggy("Porcelot Pigg",381299,4000.00);
	BrassPlus Hoggy("Horatio Hogg",382288,3000.00);
	Piggy.ViewAcct();
	cout<<endl;
	Hoggy.ViewAcct();
	cout<<"Depositing $1000 into the Hoggy Account: "<<endl;
	Hoggy.Deposit(1000.0);
	cout<<"Hoggy New balance: $"<<Hoggy.Balance()<<endl;
	cout<<"Withdrawing $4200 from the Pigg Account: "<<endl;
	Piggy.WithDraw(4200.00);
	cout<<"Pigg account balance: $"<<Piggy.Balance()<<endl;
	cout<<"Withdrawing $4200 from the Hogg Account:"<<endl;
	Hoggy.WithDraw(4200.00);
	Hoggy.ViewAcct();

	func1();

	extern double dInusebrass2;
	cout<<"来自usebrass2.cpp的double类型变量：dInusebrass2= "<<dInusebrass2<<endl;
	extern short sInusebrass2;
	cout<<"来自usebrass2.cpp的short类型变量：sInusebrass2= "<<sInusebrass2<<endl;
	system("pause");
	return 0;

}