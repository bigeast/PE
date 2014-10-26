/********************************
 * Author:			bigeast
 * Time:			2014-10-26
 * Description:		AC. answer is 453647705. 3069th.
 * 没有难度，但是注意2和5的情况比较特殊！
 ********************************/

#include <cstdio>
#include <cstring>
#include <cmath>
const int N = 100000;
char vis[1000000];
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
	for (int i = 2,f;i<N;i++) {
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
	//	if(len>1)
		{
			d = len;
			while(d%5==0){
				d/=5;
			}
			while(d%2==0){
				d/=2;
			}
			if(d!=1){
				++cnt;
				printf("%d %d %d\n",cnt,i,len);
				ans += i;
			}
		}
	}
	printf("Answer is %lld\n",ans+2+5);
	return 0;
}
