#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int N=1e6;
int prime[N/2],pf=1;
bool isprime(int n)
{
	double a=sqrt(n+1.0);
	for(int i=2;i<a;++i)
		if(n%i==0)return false;
	return true;
}
void generate()
{
	prime[1]=2;
	for(int i=3;i<N;i+=2)
		if(isprime(i))prime[++pf]=i;
	return ;
}
int main()
{
	int cnt;
	generate();
	for(int i=10,t,fac;;++i)
	{
		t=(i*i+i)/2;cnt=1;
		for(int j=1;t>=prime[j]&&j<=pf;++j)
		{
			fac=0;
			while(t%prime[j]==0)
				t/=prime[j],++fac;
			cnt*=(fac+1);
		}
		if(cnt>=500)
		{
			cout<<(i*i+i)/2<<endl;
			break;
		}
	}
	return 0;
}

