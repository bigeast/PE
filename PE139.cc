/********************************
 * Author:			bigeast
 * Time:			2015-04-29
 * Description:		AC.
 * Pythagorean Triangle 的生成公式。
 * 长边是c = m^2 + n^2 < 10^8/2，那么m,n 的范围设为<10^4/sqrt(2) = 7072
 ********************************/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;
const int N = 7072;
const int N2 = 100000000;
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
int main(int argc, const char *argv[])
{
/*
	vector<pair<int, int> > triangles;
	vector<int> sides;
*/
	map<pair<int, int>, int> triangles;
	map<pair<int, int>, int>::iterator it;
	int m2, n2, a, b, c;
	for (int m = 1; m < N; m++) {
		for (int n = 1; n < m; n++) {
			if(gcd(m, n) == 1) {
				m2 = m*m;
				n2 = n*n;
				a = m2 - n2;
				b = 2*m*n;
				c = m2 + n2;
				if(a+b+c > N2) continue;
				if(a>b)swap(a,b);
				if((m & 1) && (n & 1)) {
					triangles[pair<int, int>(a/2, b/2)] = c / 2;
				}
				else {
					triangles[pair<int, int>(a, b)] = c;
				}
/*
				if((m & 1) && (n & 1)) {
					triangles.push_back(pair<int, int>(a/2, b/2));
					sides.push_back(c/2);
				}
				else {
					triangles.push_back(pair<int, int>(a, b));
					sides.push_back(c);
				}
*/
			}
		}
	}
	int L = triangles.size();
	int res = 0;
	for (it = triangles.begin(); it != triangles.end(); it++) {
		a = it->first.first;
		b = it->first.second;
		if(it->second % (b - a) == 0)
		{
			printf("%d %d %d\n", a, b, it->second);
			res += N2 / (a + b + it->second);
		}
	}
/*
	for (int i = 0; i < L; i++) {
		if(sides[i] % abs(triangles[i].first - triangles[i].second) == 0)
		{
			printf("%d %d %d\n", triangles[i].first, triangles[i].second, sides[i]);
			res += N2 / sides[i];
		}
	}
*/
	cout<<res<<endl;
	return 0;
}
