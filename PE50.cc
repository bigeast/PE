//暴力，开始还用筛法写，后来发现不用。
//#Fri, 09 Mar 2012 14:14:24 +0800
#include <stdio.h>
#include <string.h>
#include <math.h>

const int N=1000000;
bool isp[100*N];
int p[N],f;
long long ps[N];
bool isprime(int n)
{
	double a=sqrt(n+1.0);
	for(int i=2;i<a;++i)
		if(n%i==0)return false;
	return n!=1;
}
void cal()
{
	memset(isp,true,sizeof(isp));
	//f=1;
	//while(f<100*N/2)
	//{
	//	for(int i=f+1;i<100*N/2;++i)if(isp[i])f=i;
	//	for(int i=2;i<100*N;i+=f)
	//		isp[i]=false;
	//}
	f=1;
	ps[0]=0;
	for(int i=0;i<N;++i)
	{
		isp[i]=isprime(i);
		if(isp[i])
		{
			p[f]=i;
			ps[f]=ps[f-1]+i;
			++f; //the number of primes under N is f-1
		}
	}
	return ;
}
int main()
{
	cal();
	long long t;
	for(int d=1000;d>21;--d)
		for(int i=1;i+d<f;++i)
		{
			t=ps[i+d]-ps[i];
			if(t<N)
			{
				if(isp[t])
				{
				printf("%lld=%d(%d)+...+%d(%d)\n",t,p[i+1],i+1,p[i+d],i+d);
				return 0;
				}
			}
	//		else if(isprime(t))
	//		{
	//			printf("%lld=%d(%d)+...+%d(%d)\n",t,p[i+1],i+1,p[i+d],i+d);
	//			return 0;
	//		}	
		}
}
