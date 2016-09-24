/*
 * VS默认栈大小是1M，需要在Linker和C/C++中分别设置为更大的。
 * 思路早就明白，但是下标一直搞错！
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 1000;
int main() {
	LL s[N + 2][N + 2];
	//LL s[N + 2][N + 2] = {
	//	{0},
	//	{0,15},
	//	{0,-14,-7},
	//	{0,20,-13,-5},
	//	{0,-3,8,23,-26},
	//	{0,1,-4,-5,-18,5},
	//	{0,-16,31,2,9,28,3}
	//};
	LL sum[N + 2][N + 2];
	memset(s, 0, sizeof(s));
	memset(sum, 0, sizeof(sum));

    LL t = 0;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= i; ++j) {
            t = (615949 * t + 797807) & ((1 << 20) - 1);
            s[i][j] = t - (1 << 19); 
            sum[i][j] = s[i][j] + sum[i][j - 1];
        }
    }
    LL tmp = 0;
    LL res, ans = 0;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= i; ++j) {
			tmp = 0;
            res = tmp;
            for(int level = 0; level <= N - i; ++level) {
                tmp += sum[i + level][j + level] - sum[i + level][j - 1];
                if(tmp < res) res = tmp;
            }
            if(res < ans) ans = res;
        }
    }
    cout << ans << endl;
    return 0;
}
