#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		double* price = new double[n];
		int* num = new int[n];
		for(int i = 0; i < n; ++i)
		{
			cin>>price[i];
		}
		int timeN = 1; 
		for(int i = 0; i < n; ++i)
		{
			cin>>num[i];
			timeN *= (num[i]+1);
		}

		double* value = new double[timeN];
		int m = 0; 
		for(int i = 0; i < n; ++i)
		{
			int temp = m;
			if(i == 0)
			{
				for(int j = 0; j <= num[i]; ++j)
				{

					value[m++] = j*price[i];
				}
			}
			else
			{
				for(int k = 1; k <= num[i]; ++k)
				{
					for(int j = 0; j < temp; ++j)
					{

						value[m++] = k*price[i] + value[j];				
					}
				}
			}
		}

		sort(value,value+timeN);
		// for(int i = 0; i < m; ++i)
		// {
		// 	cout<<value[i]<<' ';
		// }
		// cout<<endl;
		for(int i = 0; i < m-1; ++i)
		{
			if(value[i] == value[i+1])
				m--;
			
		}	
		cout<<m<<endl;
		delete [] price;
		delete [] num;
		delete [] value;
	}
	return 0;
}