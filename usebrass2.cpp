#include<iostream>
#include<string>
#include"brass.h"
extern double dInusebrass2 =2.0;
short sInusebrass2 =100;
void func1()
{
	using namespace std;
	
	
	Brass A("A",381299,4000.00);
	Brass B("B",381300,4000.00);
	Brass C("C",381301,4000.00);
	BrassPlus X("X",382288,3000.00);
	BrassPlus Y("Y",382289,3000.00);
	BrassPlus Z("Z",382290,3000.00);

	Brass * p_client[6];
	A.Deposit(120.12);
	p_client[0] = &A;
	p_client[1] = &B;
	p_client[2] = &C;
	p_client[2]->WithDraw(2000.0);
	p_client[3] = &Y;
	p_client[4] = &X;
	p_client[5] = &Z;

	for (int i = 0; i < 6; i++)
	{
		p_client[i]->ViewAcct();//只有当Brass声明ViewAcct为virtual才能体现多态，不然一直调用  Brass * p_client[6];也就是Brass的ViewAcct()
		cout<<endl;
		cout<<endl;
	}

	extern int iInusebrass2;

	cout<<"来自usebrassi的int类型变量：iInusebrass2= "<<iInusebrass2<<endl;
}