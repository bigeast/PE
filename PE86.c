/************************************************
Author:		bigeast
Time:		12/05/08 Tue 12:53:24 PM
State:		passed
************************************************/
//brute-force
//1-1500	669073
//1501-1800	317922
//1801-1850	59730
//986995+59730
//13005
#include <stdio.h>
#include <string.h>
#include <math.h>
#define M 1817
int sq[2*M];
int main()
{
	int cnt=0;
	int sh,t;
	for(int i=0;i<=2*M;++i)
		sq[i]=i*i;
	for(int i=1801;i<=M;++i)
		for(int j=1;j<=i;++j)
			for(int k=1;k<=j;++k)
			{
				sh=sq[j+k]+sq[i];
				t=(int)sqrt(sh);
				if(t*t==sh)++cnt;
			}
	printf("%d\n",cnt);
	return 0;
}
