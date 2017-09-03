#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 10000000;
char A[9], B[9];
bool isprime(int n) {
	for (int i = 2; i < sqrt(n) + 1; ++i) {
		if (n % i == 0) return false;
	}
	return n != 1;
}

void digit_root(char *str) {
	int res = 0;
	for (int i = 7; i >= 0 && str[i] < 10; --i) {
		res += str[i];
	}
	for (int i = 7; i >= 0; --i) {
		A[i] = res % 10;
		if (res == 0)
			A[i] = 10; // 10 代表无数字。
		else
			res /= 10;
	}
	return;
}
int pop(int n) {
	int res = 0;
	for (int i = 0; i < 8; ++i)
		if (n & (1 << i)) ++res;
	return res;
}
int dig_num[] = {
	6, 2, 5, 5, 4, 5, 6, 4, 7, 6
};
int dig_n[] = {
	(1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) + (1 << 5) + (1 << 6),
	(1 << 2) + (1 << 5),
	(1 << 1) + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 6),
	(1 << 1) + (1 << 2) + (1 << 4) + (1 << 5) + (1 << 6),
	(1 << 0) + (1 << 2) + (1 << 4) + (1 << 5),
	(1 << 0) + (1 << 1) + (1 << 4) + (1 << 5) + (1 << 6),
	(1 << 0) + (1 << 1) + (1 << 3) + (1 << 4) + (1 << 5) + (1 << 6),
	(1 << 0) + (1 << 1) + (1 << 2) + (1 << 5),
	(1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 5) + (1 << 6),
	(1 << 0) + (1 << 1) + (1 << 2) + (1 << 4) + (1 << 5) + (1 << 6)
};

int diff[11][11];
int main(int argc, char *argv[])
{
	for (int i = 0; i < 10; ++i) {
		diff[i][10] = dig_num[i]; diff[10][i] = dig_num[i];
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			diff[i][j] = pop(dig_n[i] ^ dig_n[j]);
		}
	}
	A[8] = B[8] = 0; // C string
	long long sumSam = 0, sumMax = 0;
	for (int n = N+1; n <= 2 * N; n+=2) {
	//for (int n = 137; n <= 137; ++n) {
		if (!isprime(n)) continue;

		// Init
		int t = n;
		for (int i = 7; i >= 0; --i) {
			A[i] = t % 10;
			if (t == 0)
				A[i] = 10; // 10 代表无数字。
			else
				t /= 10;
		}
		memset(B, 10, 8 * sizeof(char)); // B中存储上一个显示的数字串。

		while (true) {
			for (int i = 7; i >= 0 && A[i] != 10; --i) {
				sumSam += 2 * dig_num[A[i]];
			}
			for (int i = 7; i >= 0; --i) {
				sumMax += diff[A[i]][B[i]];
				//printf("%d %d %d\n", A[i], B[i], diff[A[i]][B[i]]);
			}
			if (A[6] == 10) { // A只剩下一位数字，结束。
				sumMax += diff[10][A[7]];
				//printf("%d %d %d\n", A[7], 10, diff[10][A[7]]);
				break;
			}
			//strcpy(B, A); // B中存储上一个显示的数字串。
			for (int i = 0; i < 8; ++i) B[i] = A[i]; // 这里错了。strcpy遇到了不是结尾标志的0.
			digit_root(A); // 计算A的各位数字之和，依旧存储在数组A中。
		}
	}
	printf("%lld %lld %lld\n", sumSam, sumMax, sumSam - sumMax);
	return 0;
}
