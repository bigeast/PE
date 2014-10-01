// 从左至右一个一个地删去数字，看剩下的数是否都是素数。同理从右至左检查是否每
// 个剩下的数都是素数。这样的素数一共有11个。原因是这11个数的前后加上3,5,7,9得
// 到的数字都不再是素数了。
// 参考的评论里zef的回答。 20141002
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N=1000000;
bool vis[N],isp[N];
bool isprime(int n)
{
	double a=sqrt(n+1.0);
	for(int i=2;i<a;++i)
		if(n%i==0)return false;
	return true;
}
int reverse(int n)
{
	int sum=0;
	while(n)
	{
		sum*=10;
		sum+=n%10;
		n/=10;
	}
	return sum;
}
bool ispm(int n)
{
	int t=n,sum=0;
	if(!isp[t])return false;
	while(t)
	{
		sum*=10;
		sum+=t%10;
		t/=10;
		if((t&&!isp[t])||!isp[reverse(sum)])return false;
	}
	return true;
}
int main()
{
	int cnt=0,ans=0,i;
	bool flag;
	for(i=2;i<N;++i)isp[i]=isprime(i);
	for(i=10;i<N;++i)
	{
		flag=ispm(i);
		if(flag)
		{
			cout<<i<<endl;
			cnt++;
			ans+=i;
			if(cnt==11)break;
		}
	}
	cout<<ans<<" "<<cnt<<endl;
	return 0;
}
