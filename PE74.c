// Very slow, need to be improved.
#include <stdio.h>
#include <string.h>
#define N 1000000
int frac[10],cnt=0;
char vis[2177282],mark[2177282];
void init()
{
	memset(vis,0,sizeof(vis));
	memset(mark,0,sizeof(mark));
	frac[0]=1;
	for(int i=1;i<10;++i)
		frac[i]=frac[i-1]*i;
	return ;
}
int cal(int n)
{
	memset(vis,0,sizeof(vis));
	vis[n]=1;
	int step=0,s;
	//printf("%d ",n);
	while(1)
	{
		s=0;
		while(n)
		{
			s+=frac[n%10];
			n/=10;
		}
		n=s;
	//	printf("%d ",s);
		mark[s]=1;
		step++;
		if(!vis[s])vis[s]=step;
		else return step;
	}
	//putchar('\n');
}
int main()
{
	init();
	//printf("%d\n",cal(169));
	//printf("%d\n",cal(69));
	for(int i=1;i<N;++i)
	{
		if(!mark[i]&&cal(i)==60)++cnt;
		if(i%(N/100)==0)printf("%d\n",cnt);
	}
	printf("%d\n",cnt);
}
