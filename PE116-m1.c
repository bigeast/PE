/************************************************
 * Author:	bigeast
 * Time:	13/01/20 Sun 12:29:04
 * State:   Correct
 * Description:		没有想想的难啊。用长度为2,3,4木板分别填满长度为50的空地。 
 ************************************************/
#include <stdio.h>
#include <string.h>
#define N 50
long long c[N][N];
int gen()
{
	for(int i=0;i<N;++i)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;++j)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	return 0;
}
int main()
{
	gen();
	long long ans=0;
	for(int k=2,t;k<5;++k)
	{
		t=N/k;
		for(int i=1,tt;i<=t;++i)
		{
			tt=N-(k-1)*i;
			printf("%lld\n",c[tt][i]);
			ans+=c[tt][i];
		}
	}
	printf("The Answer of PE116 is:\n%lld\n",ans);
	return 0;
}
