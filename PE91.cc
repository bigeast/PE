//#Sun, 26 Feb 2012 14:43:00 +0800
//竟然是枚举。。。
#include <stdio.h>
#include <string.h>

const int N=50;
int sq[N+1];
int main()
{
	int t1,t2;
	int cnt=0;
	int a,b,c;
	for(int i=1;i<=N;++i)sq[i]=i*i;
	for(int x1=0;x1<=N;++x1)
		for(int y1=0;y1<=N;++y1)
			for(int x2=0;x2<=N;++x2)
				for(int y2=0;y2<=N;++y2)
				{
					a=sq[x1]+sq[y1];
					b=sq[x2]+sq[y2];
					t1=x1>x2?x1-x2:x2-x1;
					t2=y1>y2?y1-y2:y2-y1;
					c=sq[t1]+sq[t2];
					if(a&&b&&c&&(a+b==c||a+c==b||b+c==a))cnt++;
				}
	printf("%d\n",cnt/2);
	return 0;
}
