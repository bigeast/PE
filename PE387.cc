#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;
typedef long long LL;
//const LL N = 100000000000000LL;
//const int Level = 14;
//const LL N = 10000;
const int Level = 14;
LL ans = 0;
bool isPrime(LL n) {
    if(n > 5 && (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)) return false;
    int a = (int)sqrt(n + 1.0);
    for(int i = 2; i <= a; ++i) {
        if(n % i == 0) return false;
    }
    return n != 1;
}
/*
int dfs(LL n, int digsum, int level, bool isP) {
    if(level == Level) {
        return 0;
    }
    n *= 10;
    if(n) dfs(n, digsum, level + 1, isPrime(n / digsum));
    for(int i = 1; i < 10; ++i) {
        ++n;
        ++digsum;
        if(isPrime(n) && isP) {
            ans += n;
            cout << n << endl;
        }
        if(n % digsum == 0)
            dfs(n, digsum, level + 1, isPrime(n / digsum));
    }
    return 0;
}
*/

int dfs(LL n, int digsum, int level) {
    if(level == Level) {
        return 0;
    }
    bool isP = digsum > 0 && isPrime(n / digsum);
    n *= 10;
    if(n) dfs(n, digsum, level + 1);
    for(int i = 1; i < 10; ++i) {
        ++n;
        ++digsum;
        if((n&1) && isPrime(n) && isP) {
            ans += n;
            cout << n << endl;
        }
        if(n % digsum == 0)
            dfs(n, digsum, level + 1);
    }
    return 0;
}

int main() {
    time_t start = time(0);
    //dfs(0, 0, 0, false);
    dfs(0, 0, 0);
    time_t end = time(0);
    cout << ans << endl;
    cout << "Time: " << end - start << endl;
    return 0;
}
//696067597313468
