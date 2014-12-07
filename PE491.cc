/********************************
 * Author:			bigeast
 * Time:			2014-12-07
 * Description:		AC. answer is 194505988824000.
 * 搞了好久。开始是用二进制求的，后来才意识到应该用三进制。
 ********************************/

#include <cstdio>
#include <cstring>
#include <cassert>
#define E3_10 59049
int main(int argc, const char *argv[])
{
	long long factorial[11]={1};
	int dig[10];
	long long res = 0;
	for (int i = 1; i < 11; i++) {
		factorial[i] = factorial[i-1] * i;
		printf("%lld\n",factorial[i]);
	}
	int ver = 0;
	for(int i=1,j,t,sum1,cnt,dup;i<E3_10;++i)
	{
		t = i;
		sum1 = 0;
		cnt = 0;
		dup = 0;
		j = 0;
		memset(dig,0,sizeof(dig));
		while(t)
		{
			dig[j] = t%3;
			sum1 += dig[j]*j;
			cnt += dig[j];
			if(dig[j]==2)dup++;
			t /= 3;
			++j;
		}
		if(cnt != 10){
			continue;
		}
/*
		if(sum1 == 23 || sum1 == 34 || sum1 == 45 || sum1 == 67 || sum1 == 56)
		{
			res += (((10-dig[0])*factorial[9])>>dup) * (factorial[10]>>dup);
		}
*/
		if(sum1 == 23 || sum1 == 34)
		{
			res += (((10-dig[0])*factorial[9])>>dup) * (factorial[10]>>dup);
			t = 2 - dig[0];
			res += (((10-t)*factorial[9])>>dup) * (factorial[10]>>dup);
		}
		else if(sum1 == 45){
			res += (((10-dig[0])*factorial[9])>>dup) * (factorial[10]>>dup);
		}
	}
	printf("%lld\n",res);
	return 0;
}
