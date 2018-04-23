/*
 * PE622. Accepted. 本质上就是求使得 2^60%M = 1 的 M， 可以分解2^60 - 1，
 * 得到所有的约数，然后检查最小周期是否是60。
 * Pollard-Pho 算法，还有得到所有约数的算法，有待优化。
 * 精度问题，由于 int 型的溢出问题，导致了较长时间的 debug。
 * written by bigeast
 *
 * Mon Apr 23 20:42:23 CST 2018
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int cards[100];
int c[10000];
const int N = 52;
const int anchor = 1;
#define RED "\x1b[31m"
#define RESET "\x1b[0m"
int swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
    return 0;
}
int shuffle(int *a, int len)
{
    int i = 0, j = 0, k = 0;
    int n = len / 2;
    for(int idx = 0; idx < n; ++idx)
    {
        c[k++] = a[idx];
        c[k++] = a[idx + n];
    }
    memcpy(a, c, sizeof(a[0]) * len);
    return 0;
}
int exp_n(int a, int n, int M)
{
    if(n == 0) return 1;
    int t = exp_n(a, n/2, M);
    t = t * t % M;
    if(n % 2) return t * a % M;
    else return t;
}
// 找到规律：2^i%(N-1) 的周期。
/*
int main(int argc, const char *argv[])
{
    for(int i = 0; i < N; ++i)
    {
        cards[i] = i;
    }

    vector<int> pos;
    printf("%4d. %4d", 0, exp_n(2, 0, N - 1));
    for(int i = 0; i < N; ++i)
    {
        if(cards[i] == anchor) 
        {
            pos.push_back(i);
            printf(RED);
        }
        printf("%2d ", cards[i]);
        if(cards[i] == anchor) 
            printf(RESET);
    }
    printf("\n");
    int res = 0;
    do
    {
        shuffle(cards, N);
        ++res;
        printf("%4d. %4d", res, exp_n(2, res, N - 1));
        for(int i = 0; i < N; ++i)
        {
            if(cards[i] == anchor) 
            {
                pos.push_back(i);
                printf(RED);
            }
            printf("%2d ", cards[i]);
            if(cards[i] == anchor) 
                printf(RESET);
        }
        printf("\n");
    }while(cards[1] != 1);
    for(auto item: pos)
        printf("%d ", item);
    printf("\n%d\n", res);
    return 0;
}
*/
struct FacItem {
    int base;
    int exp;
};
FacItem power2to60_1[] = {
    {3, 2},
    {5, 2},
    {7, 1},
    {11, 1},
    {13, 1},
    {31, 1},
    {41, 1},
    {61, 1},
    {151, 1},
    {331, 1},
    {1321, 1}
};
int genDivisor(unsigned long long cur, FacItem *a, int n, int N, vector<unsigned long long> &res)
{
    if(n == N) 
    {
        res.push_back(cur);
        return 0;
    }
    genDivisor(cur, a, n + 1, N, res);
    for(int i = 1; i <= a[n].exp; ++i)
    {
        cur *= a[n].base;
        genDivisor(cur, a, n + 1, N, res);
    }
    return 0;
}
typedef unsigned long long LLU;
int period(LLU n)
{
    LLU res = 0;
    LLU a = 1;
    do{
        a *= 2;
        a %= n - 1;
        ++res;
    }while(a != 1 && res < 60);

    return a == 1 ? res : -1;
}
int main(int argc, const char *argv[])
{
    int p;
    vector<unsigned long long> divisors;
    genDivisor(1, power2to60_1, 0, sizeof(power2to60_1)/sizeof(power2to60_1[0]), divisors);

    unsigned long long sum = 0;
    int cnt = 0;
    for(auto item: divisors)
    {
        if(item + 1 <= 4) continue;
        p = period(item + 1);
        //if(p > 0 && p != 60)
        if(p == 60)
        {
            sum += item + 1;
            cout << item + 1 << " " << p << endl;
            cnt++;
        }
    }
    cout << "Answer is " << sum << endl;
    return 0;
}
