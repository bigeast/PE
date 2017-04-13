#include <algorithm>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#define DIV_FUN 0   // div function is even slower than '% then /'.
#define OPT_248 1   // this is a big improvement.
#if OPT_248
unsigned int bases[] = { 2,4,8,3,5,6,7,9,10,11 };
#else
unsigned int bases[] = { 2,3,4,5,6,7,8,9,10,11 };
#endif
#if DIV_FUN
bool check(unsigned long long n) {
    unsigned int mask, base;
    long long num;
    lldiv_t divres;
    bool res = true;
    size_t len = sizeof(bases) / sizeof(bases[0]);
    for(int idx = 0; idx < len; ++idx){
        base = bases[idx];
        num = n;
        mask = 0;
        while(num) {
            divres = div(num, base);
            mask |= (1 << divres.rem);
            if(mask == (1 << base) - 1) break; // already fit.
            num = divres.quot;
        }
        if(mask != (1 << base) - 1) {
            res = false;
            break;
        }
    }
    return res;
}
#else
bool check(unsigned long long n) {
    unsigned int mask, base;
    long long num;
    bool res = true;
    size_t len = sizeof(bases) / sizeof(bases[0]);
    for(int idx = 0; idx < len; ++idx){
        base = bases[idx];
        num = n;
        mask = 0;
        while(num) {
            mask |= (1 << (num % base));
            num /= base;
            if(mask == (1 << base) - 1) break; // already fit.
        }
        if(mask != (1 << base) - 1) {
            res = false;
            break;
        }
    }
    return res;
}
#endif
int main() {
    //string str("0123456789ab");
    char str[]="0123456789ab";
    unsigned long long n, res = 0;
    int cnt = 0;
    do{
        n = strtoll(str, nullptr, 12);
        if(check(n)) {
            ++cnt;
            cout<<cnt<<": "<<n<<endl;
            res += n;
            if(cnt == 10) {
                cout << "res is: " << res << endl;
                return 0;
            }
        }
    } while(next_permutation(str, str+12));
    return 0;
}
