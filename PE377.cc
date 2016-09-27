#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
//#include <ttmath/ttmath.h>
using namespace std;
typedef long long LL;
//string str("");
char str[20];
const LL M = 1000000000;
int N; // digsum of last 9 digits.
LL ans = 0, ans13 = 0;
LL pow13[20];
LL exp_pow_n[18][100];
LL exp_mod(LL a, LL n, LL mod) {
	if (n == 0) return 1;
	LL t = exp_mod(a, n / 2, mod);
	t *= t; t %= mod;
	if (n & 1) {
		t *= a; t %= mod;
	}
	return t;
}
int idx = 0;
LL dfs13(int n) {
	if (n == 0) {
		str[idx] = 0;
		LL m = strtoll(str, NULL, 10);
        cout << str << endl;
		ans13 += m;
		ans13 %= M;
		return 0;
	}
	if (n < 0) return -1;
	for (int i = 1; i < 10; ++i) {
		str[idx++] = '0' + i;
		dfs13(n - i);
		--idx;
	}
	return 0;
}

LL dfs(int n) {
	if (n < 0 || idx > 9) return 0;
	else if (n > 9 * (9 - idx)) return 0;
	else if (n == 0 && idx == 9) {
		// cout << N << ": " << str << endl;
		str[idx] = 0;
		LL res = strtoll(str, NULL, 10);
		LL m = 0;
		LL resL, resR, mL, mR;
		for (int i = 2; i < 18; ++i) {
			//m = exp_mod(2, pow13[i] - N, M);
			m = exp_pow_n[i][N];
			//ans += (m * res) % M; // fuck, LL may overflow here!
			resL = res / 100000; resR = res % 100000;
			mL = m / 10000; mR = m % 10000;
			ans += (100000 * resL * mR) % M; ans %= M;
			ans += (10000 * resR * mL) % M; ans %= M;
			ans += (resR * mR) % M; ans %= M;
            //cout << ans << endl;
		}
		return 0;
	}
	for (int i = 1; i < 10; ++i) {
		str[idx++] = '0' + i;
		dfs(n - i);
		idx--;
	}
	return 0;
}
int main() {
	time_t start = time(0);
	pow13[0] = 1;
	for (int i = 1; i < 18; ++i) {
		pow13[i] = pow13[i - 1] * 13;
	}

	for (int i = 1; i < 18; ++i) {
		for (int j = 9; j <= 81; ++j) {
			exp_pow_n[i][j] = exp_mod(2, pow13[i] - j - 1, M);
		}
	}

	dfs13(13);
	cout << ans13 << endl;
	ans13 %= M;
	assert(idx == 0);
	//assert(str.size() == 0);
	//for (int i = 9; i <= 81; ++i) {
	for (int i = 81; i >= 9; --i) {
		N = i;
		dfs(N);
		time_t end = time(0);
		cout << N << " ans " << ans << " time: " << end - start << "s" << endl;
	}
	ans += ans13;
	ans %= M;
	time_t end = time(0);
	cout << ans << endl;
	cout << "Running in " << end - start << "s" << endl;
	return 0;
}
