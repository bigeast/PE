/*
 * 发现到后面，n的末位数字都是9了。一想，根据fn的性质，n中的数字排序不影响fn，因此使得g[i]最小的n一定是各位数字递增的。
 * 暴力的代码如下，下个版本换dfs试试！
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10000;
typedef long long LL;
int main() {
    int factorial[10];
    factorial[0] = 1;
    LL g[N];
    LL  n, fn, sfn;
    int maxsfn = 0;
    memset(g, 0, sizeof(g));
    for(int i = 1; i < 10; ++i)
        factorial[i] = i * factorial[i - 1];
    for(long long i = 1; i < 1e8; i++) {
        n = i;
        fn = 0;
        while(n) {
            fn += factorial[n % 10];
            n /= 10;
        }
        n = fn;
        sfn = 0;
        while(n) {
            sfn += n % 10;
            n /= 10;
        }
        if(g[sfn] == 0) {
            g[sfn] = i;
            if(sfn > maxsfn) maxsfn = sfn;
        }
        //cout << "n: " << i << " fn: " << fn << " sfn: " << sfn << " gn: " << g[i] << endl;
    }
    int sg = 0, t;
    int cnt[10];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= maxsfn; ++i) {
        cout << i << ": " << g[i] << endl;
        t = g[i];
        while(t) {
            sg += t % 10;
            cnt[t % 10]++;
            t /= 10;
        }
    }
    cout << sg << endl;
    for(int i = 0; i < 10; ++i) {
        cout << "i: " << i << " cnt: " << cnt[i] << endl;
    }

    /*sort(g, g+maxsfn);
    for(int i = 1; i < maxsfn; ++i) {
        cout << i << ": " << g[i] << endl;
    }*/
    return 0;
}
