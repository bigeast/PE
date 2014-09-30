//计算一个数所有约数的和，只需知道它的素因数分解，然后根据排列组合即可得
//还是isabant函数一直出错，facsum初始值应为1
//复习了bsearch
//2011年 09月 13日 星期二 16:44:40 CST
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
const int N=29000;
int prime[N],pf=0,abant[N],af=0;
bool isprime(int n)
{
	double a=sqrt(n+1.0);
	for(int i=2;i<a;++i)
		if(n%i==0)return false;
	return n!=1;
}
bool isabant(int n)
{
	int t=n,f=0,facsum=0,fac=1,ac;
	while(t>1&&f<pf)
	{
		ac=1;
		if(t%prime[f]==0)
		{
			facsum=1;
			while(t%prime[f]==0)
			{
				ac*=prime[f];
				facsum+=ac;
				t/=prime[f];
			}
			fac*=facsum;
		}
		++f;
	}
	return fac-n>n;
}
int cmp(const void *p1,const void *p2)
{
	return (*(int *)p1-*(int *)p2);
}
int main()
{
	long long ans=0;
	ofstream fout("23cantab");
	for(int i=2;i<28125;++i)
		if(isprime(i))prime[pf++]=i;
	for(int i=10;i<28125;++i)
		if(isabant(i))
		{	abant[af++]=i;//fout<<i<<endl;
		}
	int k1,k2;
	int *p=NULL;
	for(int i=1;i<28124;++i)
	{
		p=NULL;
		for(int j=0;;++j)
		{
			k1=abant[j];k2=i-k1;
			if(k2<k1)break;
			p=(int *)(bsearch(&k2,abant,af,sizeof(int),cmp));
			if(p!=NULL)
			{
//				fout<<i<<" "<<k1<<" "<<k2<<endl;
				break;
			}
		}
		if(p==NULL)
		{
			ans+=i;
//			fout<<i<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
