#include <iostream>
#include <unordered_map>
using namespace std;
const int N = 100;
long long f[N];
void genFib() {
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < N; ++i) {
        f[i] = f[i - 1] + f[i - 2];
        //cout<<i << " : " << f[i] <<endl;
    }
}
int getPisanoPeriod(int n) {
    int modules[N];
    int res = -1;
    for (int i = 1; i < N - 1; ++i) {
        modules[i] = f[i] % n;
        if (module_map.find(m) != module_map.end()) {
            int m2 = f[i + 1] % n;
            res = i - module_map[m];
            cout<< "res " << i << " : " << m <<endl;
        }
        module_map[m] = i;
        cout<< i << " : " << m <<endl;
    }
    return res;
}
int main() {
    genFib();
    getPisanoPeriod(19);
        /*
    for (int i = 1; i < 50; ++i) {
        cout << i << " : " << getPisanoPeriod(i) << endl;
        if (getPisanoPeriod(i) == 18) {
            cout<<i<<endl;
        }
    }
        */
    return 0;
}
