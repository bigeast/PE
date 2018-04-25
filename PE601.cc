/*
 * streak(n), smallest positive integer k suck that n+k is not 
 * divisible by k+1.
 *
 * written by bigeast
 *
 * Wed Apr 25 21:50:46 CST 2018
 */
#include <stdio.h>
typedef unsigned long long ULL;

#define streak(n, k) do {\
    k = 1;\
    while((n + k) % (k + 1) == 0)\
    {\
        ++k;\
    }\
} while(0)\

int main(int argc, const char *argv[])
{
    ULL res = 0;
    ULL k = 0;
    for (int idx = 1; idx <= 15; idx++) {
        ULL cnt = 0;
        for (ULL n = 2; n < (1<<(2 * idx)); n++) {
            if((n + idx) % (idx + 1) == 0) continue;
            streak(n, k);
            if(k == idx) ++cnt;
        }
        printf("%d %llu\n", idx, cnt);
        fflush(stdout);
        res += cnt;
    }
    printf("Answer is %llu\n", res);
    return 0;
}
