/*
https://projecteuler.net/thread=131;page=9
还是要从数论上分析啊。因为p是素数，因此(n, n+p) = 1，那么如果n^2(n+p) = m^3，只能让n和n+p都为立方数，所以就要检查两个立方数之差是否是素数。
由于a^3 - b^3 = (a-b)(a^2+ab+b^2)，只有当a-b=1时，a^3-b^3才可能为素数。因此只需要检查相邻的两个立方数之差是否为素数。
也等价于检查3k^2+3k+1是否为素数。
 */
#include <iostream>
#include <cmath>
#include <algorithm>
#include <ttmath/ttmath.h>
#include <ctime>
using namespace std;
typedef ttmath::Big<1, TTMATH_BITS(100)> MyBig;
//typedef long long MyBig;

typedef ttmath::Int<TTMATH_BITS(512)> MyInt;
typedef long long LL;
const int N = 1000000;
const int K = 5000;
bool isPrime(LL n) {
	if (n > 5 && (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)) return false;
	LL a = sqrt(n + 1.0);
	for (int i = 2; i < a + 1; ++i)
		if (n % i == 0) return false;
	return n != 1;
}
int main() {
	time_t start = time(0);
	LL cubic[K + 1];
	for (LL i = 1; i < K; ++i) cubic[i] = i * i * i;
	LL p;
	MyBig n, m, m3, third(1 / 3.), three(3);
	MyBig root, m3t, eps;
	int k, oldk;
	int cnt = 0, offS = 0;
	for (p = 2; p <= N; ++p) {
		if (isPrime(p)) {
			for (k = oldk + 1; k < oldk + 20; ++k) {
				n = cubic[k];
				m3 = n * n * (n + p);
				
				m3t = m3;
				m3.Pow(third);
				m3 += 0.5; root = m3.ToInt();  // round
				m = root;
				root.Pow(three);
				//cout << p << " " << m3t << " " << root << endl;
				//root -= m3t;
				//if (root < 1e-5 && root > -1e-5) {
				if(root == m3t) {

		/*		root = pow(m3, 1 / 3.) + 0.5;
				m = root;
				if(root * root * root == m3) {*/
					cout << cnt << " p: " << p << " n: " << n << "(" << k << ")" << " m: " << m << endl;
					oldk = k;
					++cnt;
					break;
				}
			}
		}
	}
	time_t end = time(0);
	cout << "User time:" << end - start << "seconds" <<endl;
	cout << "There are " << cnt << " such primes." << endl;
	return 0;
}
