/*
 * 2016/09/26 周一  0:51:09 
 * 思路清晰，一次做对。
 */
#include <iostream>
#include <vector>
using namespace std;
const int N = 12;
int pop(int n) {
    int ans = 0;
    while(n) {
        if(n&1) ++ans;
        n /= 2;
    }
    return ans;
}
int main() {
    vector<int> B, C;
    int ans = 0, t;
    for(int i = 1; i < (1 << N);++i) {
        t = pop(i);
        if(t % 2 == 0 && t >=4) { // t为B并C
            int cnt = 0, mask;
            for(int j = 1; j < (1 << t) - 1; ++j) { // 遍历B与C的划分
                mask = j;
                B.clear();
                C.clear();
                for(int k = 0; k < t; ++k) {
                    if(mask & (1<<k)) B.push_back(k);
                    else C.push_back(k);
                }
                if(B.size() == C.size()) { // 只有B，C元素个数相等时需要计算和是否相等
                    if(B[0] > C[0]) continue; // 防止计数两次。假设B[0]<C[0]
                    bool needCheck = false;
                    for(int ii = 1, len = B.size(); ii < len; ++ii) {
                        if(B[ii] > C[ii]) {
                            needCheck = true;
                            break;
                        }
                    }
                    if(needCheck) ++cnt;
                }
            }
            ans += cnt;
        }
    }
    cout << ans << endl;
    return 0;
}
