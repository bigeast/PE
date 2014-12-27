/********************************
 * Author:			bigeast
 * Time:			2014-10-26
 * Description:		AC. answer is 843296. 3617th
 *
 * 还是repunit的问题。之前看过，根本没有思路，但是有了PE129和PE130作为铺垫之后
 * ，就很简单了！有意思的是，题目要求的是前40个因子，第39和第40个之间差了好多
 * ，算第40个跟算前39个的时间差不多。还有,vis数组越大，运行就越慢。第39个因子
 * 是78601，78601*9的数组，vis设为10^6足够；第40个就是16001了，乘以九之后超出了10^6!
 * PS: 把vis的类型从int改为char，运行时间减少了一半！
 ********************************/

#include <cstdio>
#include <cstring>
#include <cmath>
const int N = 1000000000;
char vis[2000000];
int isprime(int n)
{
	double a = sqrt(n+1);
	for (int i = 2; i <= a; i++) {
		if(n%i==0) {
			return 0;
		}
	}
	return n!=1;
}
int main(int argc, const char *argv[])
{
	long long d,n,len,ans = 0;

	int cnt = 0;
	for (int i = 2,f;;i++) {
		if(i%10000==0)printf("%d\n",i);
		if(!isprime(i)) {
			continue;
		}
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
				break;
			}
			else {
				vis[n] = f;
			}
		}
		if(len>1&&N%len==0){
			++cnt;
			printf("%d %d\n",cnt,i);
			ans += i;
			if(cnt==40) {
				break;
			}
		}
	}
	printf("Answer is %lld\n",ans);
	return 0;
}
