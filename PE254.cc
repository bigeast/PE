/*
* 发现到后面，n的末位数字都是9了。一想，根据fn的性质，n中的数字排序不影响fn，因此使得g[i]最小的n一定是各位数字递增的。
* 暴力的代码如下，下个版本换dfs试试！
*
* 用整数计算很容易就溢出了。换成字符串。迭代到30层（10^30次方）时，只能得到g[59] = 122456679999999999999999999999，这样是无法计算出g[150]的。
* 必须从数学上估计。
* Map[Total, IntegerDigits[Factorial[Range[0, 9]]], 1]
* {1, 1, 2, 6, 6, 3, 9, 9, 9, 27}
* 要计算使得 digsum(digfacsum(n)) = 150 的最小的n，digfacsum(n)至少需要150/9 = 17位数字，而每个数字阶乘最多贡献出27，就需要n的位数至少是1e17/27=3703703703703703.5 = 3.7e15 位！这个暴力根本无法计算，用字符串模拟也不行！所以答案才要求计算的是g[i]的各位数字之和而不是g[i]!
* 可见n中末位的8,9越多，对digfacsum的贡献越大，这样n的位数也可以越小。所以应该从n的最小可能位数开始遍历，并且n的后面数字都是9，并不断减小9的个数，剩下的暴力。
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int N = 10000;
typedef long long LL;
int factorial[10];
string g[N];
string str;
int maxsfn = 0;
int dfs(int level, LL fn) {
	if (level == 30) return 0;
	for (int i = (level == 0 ? 1 : (str[level - 1] - '0')); i < 10; ++i) {
		str += '0' + i;
		LL new_fn = fn + factorial[i];
		LL new_sfn = 0;
		while (new_fn) {
			new_sfn += new_fn % 10;
			new_fn /= 10;
		}
		if (g[new_sfn] == "" || (g[new_sfn].size() > str.size() || g[new_sfn] > str)) {
			g[new_sfn] = str;
            cout << new_sfn << " gn: " << g[new_sfn] << endl;
            if(new_sfn > maxsfn) {
                cout << new_sfn << " gn: " << g[new_sfn] << endl;
                maxsfn = new_sfn;
            }
		}
		dfs(level + 1, fn + factorial[i]);
		str.pop_back();
	}
	return 0;
}
int main() {
	factorial[0] = 1;
	memset(g, 0, sizeof(g));
	for (int i = 1; i < 10; ++i)
		factorial[i] = i * factorial[i - 1];

	dfs(0, 0);
	int sg = 0, t;
	int cnt[10];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= 100; ++i) {
		cout << i << ": " << g[i] << endl;
        for(int j = 0; j < g[i].size(); ++j) {
            sg += g[i][j] - '0';
            cnt[g[i][j] - '0']++;
        }
	}
	cout << sg << endl;
	for (int i = 0; i < 10; ++i) {
		cout << "i: " << i << " cnt: " << cnt[i] << endl;
	}

	return 0;
}
// 1333579999999999999999999
