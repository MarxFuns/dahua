#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
bool is_magicnum(int number)
{
	string s = to_string(number);
	int sum1 = 0;
	for(int i = 0; i < s.length()-1; ++i)
	{
		sum1 += int(s[i]-'0');
		int sum2 = 0;
		for(int j = i+1; j < s.length(); ++j)
		{
			sum2 += int(s[j]-'0'); 
		}
		if(sum1 == sum2)
			return true;
	}
	return false;
}
int main()
{
	int T,X;
	bool b;
	cin>>T;
	while(T--)
	{
		cin>>X;
		b = is_magicnum(X);
		cout<<b<<endl;
	}
	return 0;
}