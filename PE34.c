//个位数字的阶乘之和等于该数的所有数之和
//只需在1e7以下寻找就行
//
//因为9!*6 = 2177280 > 10^7. 20141002
#include <stdio.h>
#include <string.h>
int main()
{
	int fac[10];
	long long ans=0;
	fac[1]=fac[0]=1;
	for(int i=2;i<10;++i)fac[i]=fac[i-1]*i;
	for(int i=10,t,sum;i<1e7;++i)
	{
		sum=0;
		t=i;
		while(t)
		{
			sum+=fac[t%10];
			t/=10;
		}
		if(sum==i)ans+=i;
	}
	printf("%lld\n",ans);
}
