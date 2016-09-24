/*
 * 本身没有多少难度，就是算起来很占内存而已。这里的解法并不严谨，是遇到不小于4的，而且回文，就直接作为答案了。第五个数很难找。如果等N2xN3全部遍历完，32G内存都不够用。
 * 而且用unordered_map出人意料地快，比map快十倍感觉。第一遍还是用Python写的，直接把电脑内存跑完。然后用C++的map，结果内存耗尽重启了。。
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N2 = 30000;
const int N3 = 30000;
typedef long long T;
bool isPalindromic(T n) {
	char str[100];
	int idx = 0;
	while (n) {
		str[idx++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < idx / 2; ++i) {
		if (str[i] != str[idx - 1 - i])
			return false;
	}
	return true;
}
int main() {
	T *sq = new T[N2];
	T *cu = new T[N3];
	for (T i = 2; i < N2; ++i) sq[i] = i * i;
	for (T i = 2; i < N3; ++i) cu[i] = i * i * i;
	T t;
	unordered_map<T, int> m;
	unordered_map<T, int> res;
	int cnt = 0;
	long long ans = 0;
	for (int j = 2; j < N3; ++j) {
		for (int i = 2; i < N2; ++i) {
			t = sq[i] + cu[j];
			if (m.find(t) != m.end()) ++m[t];
			else m[t] = 1;
			if (m[t] == 4 && isPalindromic(t)) {
				res[t] = 1;
				ans += t;
				++cnt;
				cout << t << endl;
				if (cnt == 5) {
					cout << "Answer of PE348 is :"<< ans << endl;
					return 0;
				}
			}
			if (m[t] > 4 && res.find(t) != res.end()) res.erase(t);
		}
	}
	/*
	vector<T> v;
	for (auto &item : res) {
	v.push_back(item.first);
	}
	cout << "Size of exactly 4: " << v.size() << endl;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) {
	cout << v[i] << endl;
	ans += v[i];
	}

	cout << endl << ans << endl;
	*/
	delete[] sq;
	delete[] cu;
	return 0;
}
