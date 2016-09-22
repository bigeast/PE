// 2016/09/22 周四 20:06:05 
// 晕倒，答案就是按题目中所给的方法构造出来的。。
// 还是暴力搜索，难点在于每次新加入一个元素，都要判断是否会打破条件1，可以维护一个哈希表，保存已有元素所能组成的所有和。
#include <cstdio>
#include <vector>
#include <map>
#include <cassert>
using namespace std;
const int N = 7;
map<int, int> allsum;
int dfs(int *a, int n) {
	if (n == N) {
		for (int i = 0; i < 3; ++i)
			if (a[i] + a[i + 1] + a[i + 2] <= a[i + 3] + a[i + 4])
				return 0;
		if (a[0] + a[1] + a[2] + a[3] <= a[4] + a[5] + a[6]) return 0;
		int sum = a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6];
		printf("%d\t", sum);
		for (int i = 0; i < N; ++i) printf("%d", a[i]);
		printf("\n");
		return 0;
	}

	for (a[n] = a[n - 1] + 1; a[n] < a[0] + a[1]; ++a[n]) {
		bool flag = true;
		vector<int> v;
		for (auto &item : allsum) {
			if (allsum.find(item.first + a[n]) != allsum.end()) {
				flag = false;
				break;
			}
			v.push_back(item.first);
		}
		if (flag) {
			allsum[a[n]] = 1;
			for (auto &item : v) {
				allsum[item + a[n]] = 1;
			}
			dfs(a, n + 1);
			for (auto &item : v) {
				allsum.erase(item + a[n]);
			}
			allsum.erase(a[n]);
		}
	}
}
int main() {
	int a[N];
	// n >= 2
	for (a[0] = 11; a[0] < 50; ++a[0]) {
		allsum.clear();
		allsum[a[0]] = 1;
		for (a[1] = a[0] + 1; a[1] < 50; ++a[1]) {
			allsum[a[1]] = 1;
			allsum[a[0] + a[1]] = 1;
			dfs(a, 2);
			allsum.erase(a[0] + a[1]);
			allsum.erase(a[1]);
		}
		allsum.erase(a[0]);
	}
}
