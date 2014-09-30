//数据比较小，直接暴力了，连平方根优化都没写，怕出错
//分解后构造的方法不好实现，见注释掉的代码。因为要根据素因子的个数决定for循环的个数，但for循环个数不能是动态的
//注意必须a和d[a]都小于10000，并且a!=d[a]
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int N=10000;
/*
int prime[5000],pf=0;
bool isprime(int n)
{
	double a=sqrt(n+1);
	for(int i=2;i<a;++i)
		if(n%i==0)return false;
	return true;
}

int dsum(int n)
{
	int fac[10]={0},facn[10]={0},f=0;
	for(int i=1;i<=pf;++i)
	{
		while(n%prime[i]==0&&n!=1)
		{
			if(fac[f]!=prime[i])fac[++f]=prime[i];
			facn[f]++;
			n/=prime[i];
		}
	}
	for(int i=1;i<=f;++f)

}
*/
int dsum(int n)
{	
	int sum=1;
	for(int i=2;i<n;++i)
		if(n%i==0)sum+=i;
	return sum;
}
int main()
{
	int d[10000];
	long long ans=0;
	for(int i=1;i<10000;++i)
		d[i]=dsum(i);
	for(int i=1,t;i<10000;++i)
	{
		if(d[i]<10000&&d[i]!=i&&d[d[i]]==i)ans+=i;
/*		else if(d[i]>10000)
		{
			t=dsum(d[i]);
			if(t==i)ans+=i;
		}
*/
	}
	cout<<ans<<endl;
	return 0;
}
