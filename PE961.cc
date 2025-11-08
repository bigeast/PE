// ChatGPT 牛逼
// 实际编程中，踩了两个坑：
//  1. 数组没有初始化。
//  2. 存储 9 的幂次的变量，没有使用 long long，导致结果溢出。
#include <iostream>
#include <vector>
using namespace std;
const int N = 18;
int main() {
  int isWin[1<<N];
  isWin[0] = 0;
  isWin[1] = 1;
  long long ans = 9;
  int cnt = 1;
  for (int n = 2, next_n = 0; n < (1<<N); ++n) {
    //cout << "pattern: " << n << endl;
    isWin[n] = 0;
    for (int i = 0; (1 << i) <= n; ++i) {
      next_n = ((n >> (i + 1)) << i) + (n & ((1 << i) - 1));
      // cout << "next_n: " << next_n << endl;
      if (isWin[next_n] == 0) {
        isWin[n] = 1;
      }
    }
    if (isWin[n]) {
      long long pop = 1;
      for (int i = 0; i < N; ++i) {
        if (n & (1 << i)) {
          pop *= 9L;
        }
      }
      ++cnt;
      ans += pop;
    }
    // cout << "isWin: " << n << "? " << (isWin[n] ? "Yes" : "No") << endl;
    /*
    if (isWin[n]) {
      ++cnt;
      int pop = 1;
      for (int i = 0; (1 << i) <= n; ++i) {
        if ((n & (1 << i)) > 0) {
          pop *= 9;
        }
      }
      // cout << "isWin: " << n << endl;
      ans += pop;
    }
     */
  }
  cout << "ans: " << ans << endl;
  cout << "cnt: " << cnt << endl;
}
