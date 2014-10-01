#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100000;
int prime[N],ef=0,facnt[5*N];
bool isprime(int n)
{
	double a=sqrt(n+1.0);
	for(int i=2;i<a;++i)
		if(n%i==0)return false;
	return true;
}
void gen(int n)
{
	for(int i=2;i<n;++i)
		if(isprime(i))prime[++ef]=i;
}
int main()
{
	gen(10000);
	for(int i=210;i<5*N;++i)
	{
		for(int j=1,t=i;j<=ef&&t>1;++j)
		{
			if(t%prime[j]==0)
			{
				++facnt[i];
				while(t%prime[j]==0)
					t/=prime[j];
			}
		}
		if(facnt[i]==4&&facnt[i-1]==4&&facnt[i-2]==4&&facnt[i-3]==4)
		{
			facnt[i-3]=facnt[i-2]=facnt[i-1]=facnt[i]=0;
			for(int k=i-3;k<=i;++k)
			{
				cout<<k<<" ";
				for(int j=1,t=k;j<=ef&&t>1;++j)
				{
					if(t%prime[j]==0)
					{
						cout<<prime[j]<<" ";
						++facnt[k];
						while(t%prime[j]==0)
							t/=prime[j];
					}
				}
			}
			return 0;
		}
	}
}
