#include <cstdio>
#include <cstring>
const int N = 51;
int main(int argc, const char *argv[])
{
	// fa: end with length k
	// fb: end with empty
	long long fa[N],fb[N];
	long long res = 0;
	for (int k = 2; k < 5; k++) {
		memset(fa,0,sizeof(fa));
		memset(fb,0,sizeof(fb));
		fa[k] = 1;	
		for (int i = k+1; i < N; i++) {
			fb[i] = fa[i-1]+fb[i-1];
			fa[i] = fa[i-k]+fb[i-k]+1;
		}
		res += fa[50]+fb[50];
	}
	printf("%lld\n",res);
	return 0;
}
