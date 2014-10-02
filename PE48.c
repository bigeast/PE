// 连快速幂取模都用不到的暴力就可以解决。。
#include <stdio.h>
#include <string.h>
#define MOD 10000000000
int main()
{
	long long ans=0;
	for(long long i=1,fac;i<=1000;++i)
	{
		fac=1;
		for(int j=1;j<=i;++j)
		{
			fac*=i;
			fac%=MOD;
		}
		ans+=fac;
		ans%=MOD;
	}
	printf("%lld\n",ans);
	return 0;
}
