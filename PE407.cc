#include <cstdio>
#include <cmath>
const int N = 10000000;
long long cal[N];
int isprime(int n)
{
	double a = sqrt(n+1.0);
	for (int i = 2; i <= a; i++) {
		if(n%i==0){
			return  0;
		}
	}
	return 1;
}
int main(int argc, const char *argv[])
{
	long long res = 0;
	for (long long i = 0; i < N; i++) {
		cal[i] = i*(i-1);
	}
	for (int i = 1; i <= N; i++) {
	//	printf("%d ",i);
		if(isprime(i))res+=1;
		for (int j = i-1; j > 0; j--) {
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
