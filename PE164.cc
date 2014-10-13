/********************************
 * Author:			bigeast
 * Time:			2014-10-13
 * Description:		AC. answer is 378158756814587. 3382nd.
 * 周一，晚上上课的时候想到的方法，感觉挺靠谱，回来一编程，还真就对了，一次就
 * 对了，没有修改呢。那初始条件我基本是靠感觉蒙的！
 *
 * 还是动态规划，用f[n][a][b]代表长为n，以'ab'结尾的数字个数。然后f[n+1][b][c]
 * 可以根据f[n][0...9-b-c][b]求和算出来。
 * 
 * 最开始用DFS做过，太慢了，算到后来内存不够了。因为答案是10^15级别的。。
 ********************************/

#include <cstdio>
#include <cstring>
// f[n][a][b] means n legth number that end with a,b
long long f[21][10][10];
int main(int argc, const char *argv[])
{
	memset(f,0,sizeof(f));
	f[1][0][0] = 0;
	for (int i = 1; i < 10; i++) {
		f[1][0][i]=1;
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j <= 9-i; j++) {
			f[2][i][j] = 1;
		}
	}

	for (int k = 3; k <= 20; k++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j <= 9-i; j++) {
				for (int a = 0; a <= 9-i-j; a++) {
					f[k][i][j] += f[k-1][a][i];
				}
			}
		}
	}
	long long res = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			res += f[20][i][j];
		}
	}
	printf("%lld\n",res);
	return 0;
}
