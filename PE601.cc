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

ULL streak(ULL n)
{
    ULL res = 1;
    while((n + res) % (res + 1) == 0)
    {
        ++res;
    }
    return res;
}
int main(int argc, const char *argv[])
{
    int cnt = 0;
    for (int i = 2; i < 1e6; i++) {
        if(streak(i) == 6)
        {
            cnt++;
            printf("%d %llu\n", i, streak(i));
        }
    }
    printf("Answer is %d\n", cnt);
    return 0;
}
