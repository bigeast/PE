/********************************
 * Author:			bigeast
 * Time:			2014-10-19
 * Description:		AC. answer is . 47th.
 * 第一次前100.
 * 十二点多，打开newsbeuter准备看点博客啥的，结果发现PE有更新。过去看了下，发
 * 现竟然有思路。开始做。
 *
 * 后来卡到数组的大小上很长时间，最后终于过了，不过是在实验室电脑上运行出答案
 * 的，30s。我的笔记本程序会崩溃。。
 ********************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
const int N = 100000000;
const int k = 100000;
const int lnk = 16;
const int NA = N + k + 2;
using namespace std;

int main(int argc, const char *argv[])
{
	long long *d=(long long *)calloc(NA,sizeof(long long));
	long long *M=(long long *)calloc(NA,sizeof(long long));
	long long *S=(long long *)calloc(NA,sizeof(long long));
	puts("Pre begin");
	memset(d,0,sizeof(d));
	for (int i = 1; i <= NA; i++) {
		for (long long  j = i; j <= NA; j+=i) {
			d[j]++;
		}
	}
	puts("Pre calculation OK");


	long long **F=(long long**)calloc(lnk+1,sizeof(long long*));
	for (int i = 0; i < lnk+1; i++) {
		F[i] = (long long *)calloc(NA,sizeof(long long));
	}
	for (int i = 0; i < NA; i++) {
		F[0][i] = d[i];
	}
	for (int j = 1; j < lnk+1 ; j++) {
		for (int i = 0; i < NA; i++) {
			F[j][i] = max(F[j-1][i],F[j-1][i+(1<<(j-1))]);
		}
	}
	puts("F martix OK");

	for (int i = 0; i < N+k; i++) {
		M[i] = max(F[lnk][i],F[lnk][i+k-(1<<lnk)]);
	}

	long long res = 0;
	for (int i = 1; i <= N-k+1; i++) {
		res += M[i];
	}
	printf("Answer is %lld\n",res);
	return 0;
}
