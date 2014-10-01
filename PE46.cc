#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N=10000;
int prime[N],ef=0;
bool isp[N];
bool isprime(int n)
{
	double a=sqrt(n+1.0);
	for(int i=2;i<a;++i)
		if(n%i==0)return false;
	return true;
}
void gen()
{
	for(int i=2;i<N;++i)
	{
		isp[i]=isprime(i);
		if(isp[i])prime[++ef]=i;
	}
}
int main()
{
	gen();
	cout<<"Prime OK"<<endl;
	int a;
	for(int i=31;i<N;i+=2)
	{
		if(isp[i])continue;
		a=1;
		for(int j=2,t;j<=ef&&prime[j]<i;++j)
		{
			t=i-prime[j];
			if(t%2==0)
			{
				a=(int)sqrt(t/2);
				if(2*a*a==t)
				{//cout<<i<<" "<<prime[j]<<" "<<a<<endl;
					a=-1;break;}
			}
		}
		if(a>0)
		{
			cout<<i<<endl;
			return 0;
		}
	}
}
