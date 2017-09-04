#include <set>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long LL;
const LL N = 1000000000000;
int main(int argc, char *argv[])
{
    set<LL> s;
    LL n;
    LL sqrtN = sqrt(N);
    for (int b = 2; b <= sqrtN; ++b) {
        n = b + 1;
        while(n < N) {
            n = n * b + 1;
            if(n > N) break;
            s.insert(n);
        }
    }

    LL ans = 0;
    for(auto item: s) {
        ans += item;
    }
    printf("ans is %lld\n", ans + 1);
    return 0;
}
