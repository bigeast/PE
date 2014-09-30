#include <stdio.h>
#include <string.h>
int main()
{
	int f[202];
	memset(f,0,sizeof(f));
	f[0]=1;
	int cost[]={1,2,5,10,20,50,100,200};
	int i,j;
	for(i=0;i<8;++i)
	{
		for(j=cost[i];j<=200;++j)
			f[j]+=f[j-cost[i]];
	}
	printf("%d\n",f[200]);
	return 0;
}
