/********************************
 * Author:			bigeast
 * Time:			2014-10-08
 * Description:		AC. answer is 14316. 7481st
 * 思路很简单，实现细节问题很要命。
 ********************************/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 1000001;
int div_sum(int n)
{
	if(n<3)return 1;
	int a = sqrt(n+1);
	int res = 0;
	for(int i=2;i<a;++i)
	{
		if(n%i==0)
		{
			res += (i + n/i);
		}
	}
	if(a*a==n)res+=a;
	return res+1;
}
int main(int argc, const char *argv[])
{
/*
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",div_sum(n));
	}
*/
	int next[N];
	for(int i=2;i<N;++i)
	{
		next[i] = div_sum(i);
	}
	puts("OK");
	int *chain,idx=0,*vis;
	chain = (int *)calloc(N,sizeof(int));
	vis = (int *)calloc(N,sizeof(int));
	int *pos;
	int maxlen,maxi,len;
	maxlen = 0;
	maxi = 0;
	for(int i=10,t,st;i<N;++i)
	{
		if(i%100000==0)
			printf("%d\n",i);
		if(vis[i]){
			continue;
		}
		vis[i] = 1;
		t = i;
		st = next[t];
		if(t==st)continue;

		idx = 0;
		chain[idx++] = t;
		while((pos=std::find(chain,chain+idx,st))==chain+idx)
		{
			chain[idx++] = st;
			if(st>N){
				break;
			}
			vis[st] = 1;
			st = next[st];
		}
		len = idx - (pos-chain);
		if(len > maxlen)
		{
			maxlen = len;
			maxi = *pos;
		}
	}
	printf("%d %d\n",maxlen,maxi);

	return 0;
}
