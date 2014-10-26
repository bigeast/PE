/********************************
 * Author:			bigeast
 * Time:			2014-10-26
 * Description:		AC. answer is 14516824220. 2627th
 * 分层，分边。
 * 数字与它的邻居之差是素数，不是邻居本身。相差最多是一层的个数。
 * 6mins，特别慢。。
 * 好吧，Thread里有人提到一条边上除了顶点之外的点只需要考虑一个，因为差是固定
 * 的！
 ********************************/

#include <cstdio>
#include <cmath>
#include <cstring>
#define ABS(a) ((a)>0?(a):-(a))
const int MAX_LAYER = 100000;
const int N = 1000000;
const int Nth = 2000;
long long a[MAX_LAYER];
int isprime[N];
int prime_seive()
{
	memset(isprime,1,sizeof(isprime));
	isprime[0] = isprime[1] = 0;
	for (int i = 2; i < N; i++) {
		if(isprime[i]==0)continue;
		for (int j = 2*i; j < N; j+=i) {
			isprime[j] = 0;
		}
	}
	return 0;
}
int main(int argc, const char *argv[])
{
	a[0] = 1;
	for (int i = 1; i < MAX_LAYER; i++) {
		a[i] = a[i-1] + 6*i;
	}
	printf("%lld\n",a[MAX_LAYER-1]);
	prime_seive();
	long long neighbor[6],idx;
	long long cnt = 0, res = 0, n;
	long long next, prev;
	// which layer
	for (long long i = 2; i < MAX_LAYER; i++) {
		// which side
		for (long long j = 0; j < 6; j++) {
			// position in side
			for (long long k = 0; k < i; k++) {
				idx = 0;
				n = a[i-1] + i*j + k + 1;
				// first of a side
				if(k==0) {
					// the side is also the first of a layer
					if(j==0) {
						neighbor[idx++] = n - 6*(i-1) - j;
						neighbor[idx++] = n + 1;
						neighbor[idx++] = a[i];
						neighbor[idx++] = a[i]+1;
						neighbor[idx++] = a[i]+2;
						neighbor[idx++] = a[i+1];
					}
					else {
						next = n + 6*i + j;
						neighbor[idx++] = next;
						neighbor[idx++] = n - 6*(i-1) - j;
						neighbor[idx++] = n - 1;
						neighbor[idx++] = n + 1;
						neighbor[idx++] = next - 1;
						neighbor[idx++] = next + 1;
					}
				}
				// last of last side
				else if(n==a[i]) {
					neighbor[idx++] = n - 1;
					neighbor[idx++] = a[i-2] + 1;
					neighbor[idx++] = a[i-1];
					neighbor[idx++] = a[i-1] + 1;
					neighbor[idx++] = a[i+1];
					neighbor[idx++] = a[i+1] - 1;
				}
				else {
					// same position in previous layer.
					neighbor[idx++] = n - 1;
					neighbor[idx++] = n + 1;
					prev = a[i-2] + 1 + j*(i-1) + k - 1;
					neighbor[idx++] = prev;
					neighbor[idx++] = prev + 1;
					next = a[i] + 1 + j*(i+1) + k;
					neighbor[idx++] = next;
					neighbor[idx++] = next + 1;
				}

				cnt = 0;

				long long t;
				for (int id = 0; id < idx; id++) {
					t = ABS(neighbor[id]-n);
					else if(isprime[t]) {
						++cnt;
					}
				}
				if(cnt == 3) {
					++res;
					if(res==(Nth-2)) {
						printf("Answer is %lld\n",n);
						return 0;
					}
					printf("layer:%lld res:%lld n:%lld: ",i,res,n);
					for (int id = 0; id < idx; id++) {
						printf("%lld ",neighbor[id]);
					}
					printf("\n");
				}
			}
		}
	}
	return 0;
}
