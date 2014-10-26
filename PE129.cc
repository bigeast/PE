/********************************
 * Author:			bigeast
 * Time:			2014-10-26
 * Description:		AC. answer is 1000023. 3510th.
 *
 * 容易想到是求1/n的循环节。但是直接求是不对的！最好把R(k)写成(10^k-1)/9，然后
 * 再考虑循环节。
 * 还有为什么大数组在main函数中不能分配到内存？
 ********************************/

#include <cstdio>
#include <cstring>
const int N = 1000000;
int vis[10*N];
int main(int argc, const char *argv[])
{
	long long d,n,len;
	for (int i = N,f;;i++) {
		memset(vis,0,sizeof(vis));
		d = 9*i;
		n = 1;
		len = 0;
		f = 1;
		vis[1] = 1;
		while(1)
		{
			++f;
			n*=10;
			n %= d;
			if(vis[n]) {
				len = f - vis[n];
				break;
			}
			else if(n==0) {
				len = 0;
				break;
			}
			else {
				vis[n] = f;
			}
		}
		if(len>N) {
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
