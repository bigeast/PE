//#Mon, 27 Feb 2012 00:04:24 +0800
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int a,int b)
{
	if(b==0)return a;
	return a<b?gcd(b,a):gcd(b,a%b);
}
int main()
{
	int f=0;
	for(int i=4;i<12001;++i)
		for(int j=i/3-1;j<=i/2;++j)
		{
			if(gcd(j,i)==1)
			{
				if(3*j>i&&2*j<i)
				{
					++f;
	//				printf("%d\t%d\n",j,i);
				}
			}
		}
	printf("%d\n",f);
	return 0;
}
