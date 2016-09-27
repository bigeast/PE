/*
 *
 MatrixPower[( {
      {3, 1, 0},
      {0, 2, 2},
      {0, 1, 3}
     } ), n - 2].{0, 0, 6} // Simplify
{2 - 2 3^(-1 + n) + 4^(-1 + n), -4 + 4^(-1 + n), 2 + 4^(-1 + n)}
A[n] = -2*3^(-1 + n) + 3*4^(-1 + n)
 */
#include <iostream>
#include <ctime>
using namespace std;
const int N = 10000000;
typedef long long LL;
// A03代表蓝色三角形有0条白边，3条红边。
// ~~B1代表从蓝色三角形生成的黄色三角形（三边都为红）。B2代表从原来的黄色继承过来的（两红一绿）。~~
// B03代表黄色三角形有0条绿边，3条红边。
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b , a % b);
}
/*
LL A03[N], A12[N], A21[N], A[N];
LL B03[N], B12[N], B21[N], B30[N], B[N];
int main() {
    A03[2] = 0;
    A12[2] = 0;
    A21[2] = 6;
    A[2] = 6;
    B03[2] = 0;
    B12[2] = 0;
    B21[2] = 0;
    B30[2] = 0;
    B[2] = 0;
    LL ans = 0;
	for (int n = 3; n < N; ++n) {

		A03[n] = 3 * A03[n - 1] +   1 * A12[n - 1];
		A12[n] =                    2 * A12[n - 1]  +   2 * A21[n - 1];
		A21[n] =                    1 * A12[n - 1]  +   3 * A21[n - 1];
		A[n] = A03[n] + A12[n] + A21[n];

        B03[n] = 3 * A03[n - 1] +   2 * A12[n - 1]  +   A21[n - 1];
		B12[n] = 6 * B03[n - 1] +   3 * B12[n - 1]  +   1 * B21[n - 1];
        B21[n] =                    2 * B12[n - 1]  +   2 * B21[n - 1];
        B30[n] =                                        1 * B21[n - 1]  +   3 * B30[n - 1];

		B[n] = B03[n] + B12[n] + B21[n] + B30[n];

        LL G = gcd(A[n], B[n]);
        ans += G;
        cout << "n: " << n << " A[n]: " << A[n] << " B[n]: " << B[n] << " gcd " << G << endl;
        //cout << "n: " << n << " B03[n]: " << B03[n] << endl;
	}
    return 0;
}
*/
LL exp_mod(LL a, LL n, LL M) {
    if(n == 0) return 1;
    LL t = exp_mod(a, n / 2, M);
    t *= t;
    t %= M;
    if(n & 1) {
        t *= a;
        t %= M;
    }
    return t;
}
int main() {
    LL a, b;
    LL ans = 0, G;
    time_t start = time(0);
    for(LL n = 3; n <= N; ++n) {
        a = 7 * n + 3;
        b = a;
        b -= exp_mod(3, n - 2, a);
        b += exp_mod(2, 2 * n - 3, a);
        b %= a;
        G = gcd(a, b);
        //cout << "n: " << n << " G: " << G << endl;
        ans += G;
    }
    time_t end = time(0);
    cout << 6 * ans << endl;
    cout << end - start << endl;
    return 0;
}
