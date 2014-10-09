/********************************
 * Author:			bigeast
 * Time:			2014-10-09
 * Description:		整数分划。
 * f[i][j]代表把整数i分成j个部分的方法数。它等于其中至少有一个1：f[i-1][j-1]。
 * 或者没有1：f[i-j][j]。n的分划数是sum{f[n]}
 ********************************/

#include <stdio.h>
#include <string.h>

const int N = 100;
int f[N+1][N+1];
int solve()
{
	// 初始化很重要。
	for(int i=1;i<=N;++i)
	{
		f[i][1]=1;
	}
	for(int i=1;i<=N;++i)
	{
		for(int j=2;j<=i;++j)
		{
			f[i][j] = f[i-1][j-1] + f[i-j][j];
		}
	}
}
int main(int argc, const char *argv[])
{
	solve();

	int n=100;
	int res=0;
	for(int i=0;i<=n;++i)
		res+=f[n][i];
	printf("%d\n",res);
	return 0;
}
