//最后找到的结果是-61,971,只有71个连续的素数，还没有题目中的多。
//后来发现例子中的1601已经超1000了。
//运行时间大概有15秒了----擦，把N去掉一个0,瞬间出答案～
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int N=1000006;
bool prime[N];
bool isprime(int n)
{
	double a=sqrt(n+1.0);
	for(int i=2;i<a;++i)
		if(n%i==0)return false;
	return true;
}
void generate()
{
	for(int i=2;i<N;++i)
		prime[i]=isprime(i);
}
int main()
{
	int maxv=0,cnt,fac,faca,facb;
	generate();
	for(int a=-999;a<1000;++a)
		for(int b=-999;b<1000;++b)
		{
			cnt=0;
			for(int i=0,t;;++i)
			{
				t=i*i+a*i+b;
				t=t>0?t:-t;
				if(!prime[t])break;
				++cnt;
			}
			if(cnt>maxv)
			{
				maxv=cnt;
				faca=a;
				facb=b;
				fac=a*b;
			}
		}
	cout<<maxv<<"\t"<<faca<<"\t"<<facb<<"\t"<<fac<<endl;
	return 0;
}
