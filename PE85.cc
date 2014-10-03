//#Sun, 26 Feb 2012 12:30:29 +0800
//开始想着挺麻烦的，似乎还要写一个类似二分法的函数
//只要假设m<=n，而m(m+1)n(n+1)=8000000.
//枚举m,得到n(n+1),开根号，近似得到n,然后在它附近算几个数就行了。
//没有往前算，但是结果对了。
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int a,b,N=8000000,rm,rn,d=1000000;
	int dt;
	for(int m=1;m<53;++m)
	{
		a=m*(m+1);
		for(int n=sqrt(N/a),i=1;n>=m&&i<4;++n,++i)
		{
			b=n*(n+1);
			dt=N-a*b;
			dt=dt>0?dt:-dt;
			if(dt<d)
			{
				d=dt;rm=m;rn=n;
			}
		}
	}
	printf("%d*%d=%d\tdif=%d\n",rm,rn,rm*rn,d);
}
