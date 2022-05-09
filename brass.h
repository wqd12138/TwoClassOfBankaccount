#ifndef BRASS_H_
#define BRASS_H_
#include<string>

class Brass
{
public:
	Brass(const std::string & s="NoName",long an = -1,double bal =0.0);
	void Deposit(double amt);
	double Balance() const;
	virtual void WithDraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass(){}
private:
	std::string fullName;
	long accNum;
	double balance;
};

class BrassPlus:public Brass
{
public:
	BrassPlus(const std::string &s="NoName",long an =-1,double bal =0.0,double m1=500,double r =0.11125);
	BrassPlus(const Brass &ba,double m1=500.0,double r=0.11125);
	virtual void ViewAcct() const;
	virtual void WithDraw(double amt) ;
	void ResetMax(double m){maxLoan = m;}
	void ResetRate(double r){rate = r;}
	void ReaetQwes(){owesBank=0.0;}
private:
	double maxLoan;
	double rate;
	double owesBank;
};
void func1();
#endif