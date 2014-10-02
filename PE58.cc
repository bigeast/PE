#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
bool isprime(long long n)
{
	double a=sqrt(n+1.0);
	for(int i=2;i<a;++i)
		if(n%i==0)return false;
	return true;
}
int main()
{
	double ratio;
	int ans=3;
	for(long long n=3;;n+=2)
	{
		if(isprime(n*n+n+1))++ans;
		if(isprime(n*n+2*n+2))++ans;
		if(isprime(n*n+3*n+3))++ans;
		if(isprime(n*n+4*n+4))++ans;
		ratio=(double)ans/(2*n+3.0);
		if(ratio<0.1)
		{
			cout<<n+2<<endl;
			break;
		}
		if(n<30)cout<<ans<<"\t"<<ratio<<endl;
	}
	return 0;
}
