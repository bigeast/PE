/********************************
 * Author:			bigeast
 * Time:			2014-10-16
 * Description:		AC. answer is 209566. 3567th
 * Easy as PE173.
 ********************************/
#include <cstdio>
#include <cstring>
#include <cmath>
int main(int argc, const char *argv[])
{
	int all = 1000000;
	int N[1000],ni,a;
	memset(N,0,sizeof(N));
	for (int i = 1; i <= all/4; i++) {
		a = ((sqrt(4*i+1)-1)/2);
		ni = 0;
		for (int j = 1; j <= a; j++) {
			if(i%j==0) {
				++ni;
			}
		}
		N[ni]++;
	}
	int ans=0;
	for (int i = 1; i <= 10; i++) {
		ans += N[i];
	}
	printf("%d\n",ans);
	return 0;
}
