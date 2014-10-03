#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 1500000
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int tri[N+1];
	memset(tri,0,sizeof(tri));
	int m,n,limit=(int)sqrt(N/2+1.0);
	int a,b,c,p;
	for(m=2;m<limit;++m)
		for(n=1;n<m;++n)
		{
			if(((m+n)&1)&&gcd(m,n)==1)
			{
				a=m*m-n*n;
				b=m*m+n*n;
				c=2*m*n;
				p=a+b+c;
				while(p<=N)
				{
					tri[p]++;
					p+=a+b+c;
				}
			}
		}
	int cnt=0;
	for(m=1;m<=N;++m)
		if(tri[m]==1)++cnt;
	printf("%d\n",cnt);
	printf("%d %d\n",120,tri[120]);
	return 0;
}
