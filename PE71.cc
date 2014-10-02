//#Sun, 26 Feb 2012 11:22:05 +0800
//开始还从分母为1开始算，发现真是傻。

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//const int N=1000000;
//typedef struct p
//{
	//int a;
	//int b;
	//double val;
//}Frac;
//Frac P[N];
//int f=0;
const int N=100;
int gcd(int a,int b)
{
	if(b==0)return a;
	return a<b?gcd(b,a):gcd(b,a%b);
}
int main()
{
	double m=3.0/7.0,d=1.0,t;
	int a=2,b=5;
	//for(int i=8;i<101;++i)
	//	for(int j=2*i/5;j<=i/2;++j)
	for(int i=999900;i<1000001;++i)
		for(int j=428300;j<430000;++j)
		{
	//		printf("(%d,%d)=%d	",i,j,gcd(i,j));
			if(gcd(i,j)==1)
			{
	//			printf("%lf\n",t);
				if(7*j<3*i&&a*i<b*j)
				{
					a=j;b=i;	
				}
			}
		}
	printf("%d\t%d\n",a,b);
	printf("%.25f\t%.10f\n",m,m-(double)a/b);
	return 0;
}
