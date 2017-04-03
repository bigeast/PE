#include <algorithm>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
unsigned int bases[] = { 2,4,8,3,5,6,7,9,10,11 };
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
int main() {
    string str("0123456789ab");
    unsigned long long n, res = 0;
    int cnt = 0;
    do{
        n = strtoll(str.c_str(), nullptr, 12);
        if(check(n)) {
            ++cnt;
            cout<<cnt<<": "<<n<<endl;
            res += n;
            if(cnt == 10) return 0;
        }
    } while(next_permutation(str.begin(), str.end()));
    cout << "res is: " << res << endl;
    return 0;
}
