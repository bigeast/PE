// 2016/09/22 周四 20:56:35 
// STL的使用。之前一直没思路估计是没想到用暴力搜索。。
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cassert>
using namespace std;

bool special_subset_sumQ(vector<int> &s) {
	sort(s.begin(), s.end());
	int len = s.size();
    assert(len >= 7 && len <= 12);
    //for(auto n: s) cout<<n<<" ";
    //cout<<endl;
	// 条件二：
	if (s[0] + s[1] <= s[len - 1]) return false;
	for (int lenA = 3; lenA <= len; ++lenA) { // 元素个数为lenA的子集是否都比元素个数为lenA - 1的子集大。
											  // lenA 小于 len / 2 + 1 即可
		int T = 0;
		for (int i = 0; i < lenA - 1; ++i) T += s[len - 1 - i]; // 元素个数为lenA - 1的最大子集

																// 元素个数为lenA的最小子集
		int test = 0;
		for (int j = 0; j < lenA; ++j) {
			test += s[j];
		}
		if (test <= T) return false;
	}

	// 条件一：
    unordered_map<int, int> m;
    for (int i = 0; i < len; ++i) {
        vector<int> v;
        if (m.find(s[i]) != m.end()) return false;
        for (auto &item : m) {
            if (m.find(s[i] + item.first) != m.end()) return false;
            v.push_back(item.first); // 注意这里要先保存起来，因为m是不断变化的，不能直接在这里更新m。
        }
        m[s[i]] = 1;
        for(auto n: v)
            m[s[i] + n] = 1;
    }
	return true;
}
int main() {
	string str;
	ifstream fin("p105_sets.txt");

	long long ans = 0;
	while (fin >> str) {
		stringstream ss(str);
		vector<int> v;
		int n;
		while (ss >> n) {
			v.push_back(n);
			if (ss.peek() == ',') ss.ignore();
		}
		if (v.size() > 0 && special_subset_sumQ(v)) {
			int sum = 0;
			for (int n : v) sum += n;
			ans += sum;
		}
	}
	cout << ans << endl;
}
