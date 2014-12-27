/********************************
 * Author:			bigeast
 * Time:			2014-10-26
 * Description:		AC. answer is 149253. 3296th
 * 基于PE129，注意55符合除了gcd(55,10)==1之外的所有条件。
 * 运行时间1min6s。
 ********************************/

#include <cstdio>
#include <cstring>
#include <cmath>
const int N = 20000;
int vis[10*N];
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
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main(int argc, const char *argv[])
{
	long long d,n,len,ans = 0;

	int cnt = 0;
	for (int i = 2,f;i<N;i++) {
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
		if(gcd(i,10)==1&&!isprime(i)&&len>1&&(i-1)%len==0){
			printf("%d\n",i);
			ans += i;
			++cnt;
			if(cnt==25) {
				break;
			}
		}
	}
	printf("Answer is %lld\n",ans);
	return 0;
}
