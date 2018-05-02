#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
double handle_data_func(int M,int N,int X,double &T1)
{
	double T0 = 0;
	double X8 = 0.8*X, X6 = 0.6*X; 
	// if(M <= N)
	// 	return 0;
	// double t0_8 = ceil(X8/(M-N));
	// double t8_6 = ceil((t0_8*(M-N)-X6)/N);
	// T0 = t0_8 + t8_6;
	// double last = t0_8*(M-N) - t8_6*N;
	// double t6_8 = ceil((X8-last)/(M-N));
	// T1 = t6_8 + t8_6;

	double t0_8 = X8/(M-N);
	double t8_6 = (t0_8*(M-N)-X6)/N;
	T0 = t0_8 + t8_6;
	double last = t0_8*(M-N) - t8_6*N;
	double t6_8 = (X8-last)/(M-N);
	T1 = t6_8 + t8_6;

	return T0;	
}
int main()
{
	int T,M,N,X;
	double T0=0,T1=0;
	cin>>T;
	while(T--)
	{
		cin>>M>>N>>X;
		T0 = handle_data_func(M,N,X,T1);
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<T0<<endl;
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<T1<<endl;
	}
	return 0;
}