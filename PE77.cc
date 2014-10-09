#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=1000;
int prime[N],pf;
bool isprime(int n)
{
	double a=sqrt(n+1.0);
	for(int i=2;i<a;++i)
		if(n%i==0)return false;
	return n!=1;
}
int solve()
{
	int f[N];
	memset(f,0,sizeof(f));
	for(int i=2;i<N;++i)if(isprime(i))prime[pf++]=i;
	f[0]=1;
	for(int i=0;i<pf;++i)
	{
		for(int j=prime[i];j<N;++j)
		{
			f[j]+=f[j-prime[i]];
		}
	}
	for(int i=0;i<100;++i) {
		if(f[i]>5000) {
			cout<<i<<" "<<f[i]<<endl;
			break;
		}
	}
	return 0;
}
// 不能用PE76中的方法了。
/*
int solve_b()
{
	int f[N+1][N+1];
	memset(f,0,sizeof(f));
	for(int i=2;i<=N;++i)
	{
	//	if(isprime(i))prime[pf++]=i;
		if(isprime(i))
			f[i][1] = 1;
	}
	for(int i=2;i<=N;++i)
		for(int j=2;j<=i/2;++j)
		{
			f[i][j] = f[i-2][j-1] + f[i-2*j][j];
		}
	int res;
	for(int i=2;i<=N;++i)
	{
		res = 0;
		for(int j=1;j<=i/2;++j)
		{
			res += f[i][j];
		}
		if(i<=10)printf("%d\n",res);
		if(res>5000)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
*/
int main()
{
	solve();
	return 0;
}
