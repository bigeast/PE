#include <cstdio>
#include <cmath>
const int N = 10000000;
typedef long long LL;
LL cal[N];
LL isprime(LL n)
{
	double a = sqrt(n+1.0);
	for (int i = 2; i <= a; i++) {
		if(n%i==0){
			return  0;
		}
	}
	return 1;
}
int exp_mod(int a, int n, int M) {
    if(n == 1) return a % M;
    int t = exp_mod(a, n/2, M);
    int res = (LL) t * t % M;
    if(n % 2 == 1) return (LL)res * a % M;
    else return res;
}
int main(int argc, const char *argv[])
{
	for (LL i = 1; i < N; i++) {
		cal[i] = i*(i-1);
	}
	LL res = 1;
	for (int i = 2; i <= N; i++) {
	//	printf("%d ",i);
		if(isprime(i))res += i - 1;
		for (int j = i - 1; j > 0; j--) {
			if(cal[j]%i==0) {
	//			printf("%d\n",j);
				res += j;
				break;
			}
		}
	}
	printf("%lld\n",res);
	return 0;
}
