#include <cstdio>
#include <cmath>
#include <cstring>
//const int N = 100000000;
const int N = 100000000;
const int M = 1000000007;
int primepi[N + 1];
typedef long long LL;
int u[20];
LL pn[20];
int seive(int *p, int n) {
    memset(p, 1, sizeof(int) * n);
    p[0] = p[1] = 0;
    for (int i = 2; i < n; ++i) {
        if(p[i]) {
            for (int k = 2; i * k < n; ++k) {
                p[i * k] = 0;
            }
        }
    }
    return 0;
}
bool isprimeP(int n) {
    return n != 1 && primepi[n] != primepi[n - 1];
}
int main() {
    seive(primepi, N + 1);
    for (int i = 2; i < N + 1; ++i) {
        if(primepi[i]) primepi[i] = primepi[i - 1] + 1;
        else primepi[i] = primepi[i - 1];
    }

    puts("OK");
    LL ans = 1;
    for (int i = 2, j; i <= N; ++i) {
        //printf("%d\n", i);
        j = 0;
        //memset(pn, 0, sizeof(pn));
        u[j++] = i;
        for (; primepi[u[j - 1]]; ++j) {
            u[j] = primepi[u[j - 1]];
        }
        int primeNum = 0;
        if (isprimeP(u[0]) && isprimeP(u[1])) {
            primeNum = 2;
            pn[0]++;
        }
        else if (!isprimeP(u[0]) && !isprimeP(u[1])) {
            primeNum = 0;
            pn[2]++;
        }
        else {
            primeNum = 1;
            pn[1]++;
        }
        for (int t = 2; t < j; ++t) {
            if (isprimeP(u[t])) {
                primeNum++;
            }
            pn[t + 1 - primeNum]++;
        }
    }
    for (int t = 0; t < 20; ++t) {
        if (pn[t] < 1) continue;
        printf("%d %d\n", t, pn[t]);
        ans = ans * (pn[t] % M) % M;
    }

    printf("Answer is %lld\n", ans);
    return 0;
}
