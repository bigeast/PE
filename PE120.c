#include <stdio.h>
#include <string.h>
/*
int a,md;
int expmod(int x,int n)
{
	if(n==0)return 1;
	int t=expmod(x,n/2);
	t=(t*t)%md;
	if(n&1)t*=x,t%=md;
	return t;
}
int main()
{
	int ans=0,rmax;
	for(a=3;a<=1000;++a)
	{
		md=a*a;
		rmax=a&1?(expmod(a-1,a/2)+expmod(a+1,a/2))%md:(expmod(a-1,a-1)+expmod(a+1,a-1))%md;
		ans+=rmax;
	//	printf("%d:%d\n",a,rmax);
	}
	printf("total:%d\n",ans);
	return 0;
}
*/
int main()
{
	int r,rmax,md;
	long long ans=0;
	for(int a=3;a<=1000;++a)
	{
		md=a*a;
		rmax=0;
		// n 为奇数时，剩下2*a*n，遍历n，求 2*a*n%md 的最大值
		for(int i=1;i<=md;i+=2)
		{
			r=(2*i*a)%md;
			if(r>rmax)rmax=r;
		}
		// n为偶数时，答案恒为2
		if(rmax<2)rmax=2;
	//	printf("%d %d\n",a,rmax);
		ans+=rmax;
	}
	printf("%lld\n",ans);
	return 0;
}
