//phi[8319823]=8313928	 1.00071
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=10000001;
unsigned long long euler[N+5];
int cal()
{
	for(unsigned long long i=0;i<=N;++i)euler[i]=1;
	for(unsigned long long i=2;i<=N;++i)
		if(euler[i]==1)
		{
			for(unsigned long long j=i;j<=N;j+=i)
				euler[j]*=i-1;

			for(unsigned long long j=i*i;j<=N;j*=i)
			{
				for(unsigned long long k=j;k<=N;k+=j)
					euler[k]*=i;
			}
		}
}
int main()
{
	cal();
	char ns[50],es[50];
	double res=10.0,tmp;
	int ans=1;
	for(int i=2;i<N;++i)
	{
		sprintf(ns,"%d",i);
		sprintf(es,"%lld",euler[i]);
		string a(ns,ns+strlen(ns));
		string b(es,es+strlen(es));
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		if(a==b)
		{
			tmp=(i+0.0)/euler[i];
			if(tmp<res)
			{
				ans=i;
				res=tmp;
			}
		}
	}
	cout<<ans<<endl;
	cout<<euler[ans]<<endl;
	cout<<res<<endl;
	return 0;
}
