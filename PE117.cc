/********************************
 * Author:			bigeast
 * Time:			2014-10-13
 * Description:		AC. answer is 100808458960497. 6141st
 * 是PE116的扩展，把状态数增加就可以了。之前PE116是用公式算的，不是用DP，而
 * PE117的公式没有那么容易得到，DP是比较简单的。注意这里最后要加1。
 ********************************/

#include <cstdio>
#include <cstring>
const int N = 51;
int main(int argc, const char *argv[])
{
	// f : end with empty
	// f2 : end with 2
	// f3 : end with 3
	// f4 : end with 4
	long long f[N],f2[N],f3[N],f4[N];
	memset(f,0,sizeof(f));
	memset(f2,0,sizeof(f2));
	memset(f3,0,sizeof(f3));
	memset(f4,0,sizeof(f4));
	f2[2] = 1;
	for (int i = 3; i < N; i++) {
		f2[i] = f[i-2] + f2[i-2] + f3[i-2] + f4[i-2] + 1;
		if(i>=3)f3[i] = f[i-3] + f2[i-3] + f3[i-3] + f4[i-3] + 1;
		if(i>=4)f4[i] = f[i-4] + f2[i-4] + f3[i-4] + f4[i-4] + 1;
		f[i] = f[i-1] + f2[i-1] + f3[i-1] + f4[i-1];
	}
	printf("%lld\n",f[50]+f2[50]+f3[50]+f4[50]+1);
	return 0;
}
