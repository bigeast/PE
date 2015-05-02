#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
int r1 = 5678027, r2 = 7208785;
const int N = 8000000;
short isprime[N];
int seive()
{
	memset(isprime, 0x1, sizeof(isprime));
	isprime[0] = isprime[1] = 0;
	for (int i = 2; i < N; i++) {
		if(isprime[i])
		{
			for (int j = 2*i; j < N; j+=i) {
				isprime[j] = 0;
			}
		}
	}
	return 0;
}
long long S(long long row)
{
	long long s[5];
	short *isp[5];
	int triples = 0;
	for (int i = 0, r = row - 2; r > 0 && i < 5; i++) {
		isp[i] = (short *)calloc(r + 2, sizeof(short));
		s[i] = (long long)r * (r - 1) / 2 + 1; // long long !!!
		r++;
	}
	mpz_t n;
	mpz_init(n);
	for (int i = 0; i < 5; i++) {
		mpz_set_ui(n, s[i]);
		for (int j = 0; j < row - 2 + i; j++) {
			isp[i][j] = mpz_probab_prime_p(n, 5);
			mpz_add_ui(n, n, 1);
		}
	}
	puts("OK");

	long long res = 0;
	for (int y = 0, x = 2, cnt; y < row; y++) {
		if(isp[x][y])
		{
			cnt = 0;
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					if((y+j)>=0 && (y+j)<(row+i) && isp[x+i][y+j])
					{
						++cnt;
						if(cnt == 3) {
	//						printf("%lld\n", s[x] + y);
							res += s[x] + y;
							triples++;
							goto L0;
						}
					}
				}
			}
			if(cnt > 0)
			{
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if((y+j)>=0 && (y+j)<(row+i) && isp[x+i][y+j]) {
							cnt = 0;
							for (int k = -1; k < 2; k++) {
								for (int l = -1; l < 2; l++) {
									if((y+j+l)>=0 && (y+j+l)<(row+i+k) && isp[x+i+k][y+j+l])
									{
										++cnt;
										if(cnt == 3) {
	//										printf("%lld\n", s[x] + y);
											res += s[x] + y;
											triples++;
											goto L0;
										}
									}
								}
							}
						}
					}
				}
			}
			else continue;
		}
L0:		continue;
	}
	for (int i = 0; i < 5; i++) {
		free(isp[i]);
	}
	printf("%d\n", triples);
	return res;
}
int main(int argc, const char *argv[])
{
/*
	   int n = atoi(argv[1]);
	   gmp_printf("S(%d) = %lld\n", n, S(n));
*/
	long long res1 = S(r1);
	gmp_printf("S(%d) = %lld\n", r1, res1);
	long long res2 = S(r2);
	gmp_printf("S(%d) = %lld\n", r2, res2);

	printf("Answer is %lld\n", res1 + res2);
	return 0;
}
//S(5678027) = 14932626861740 S(7208785) = 25889562032361
