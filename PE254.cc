/*
* 发现到后面，n的末位数字都是9了。一想，根据fn的性质，n中的数字排序不影响fn，因此使得g[i]最小的n一定是各位数字递增的。
* 暴力的代码如下，下个版本换dfs试试！
*
* 用整数计算很容易就溢出了。换成字符串。迭代到30层（10^30次方）时，只能得到g[59] = 122456679999999999999999999999，这样是无法计算出g[150]的。
* 必须从数学上估计。
* Map[Total, IntegerDigits[Factorial[Range[0, 9]]], 1]
* {1, 1, 2, 6, 6, 3, 9, 9, 9, 27}
* 要计算使得 digsum(digfacsum(n)) = 150 的最小的n，digfacsum(n)至少需要150/9 = 17位数字，而每个数字阶乘最多贡献出27，就需要n的位数至少是1e17/27=3703703703703703.5 = 3.7e15 位！这个暴力根本无法计算，用字符串模拟也不行！所以答案才要求计算的是g[i]的各位数字之和而不是g[i]!
* 可见n中末位的8,9越多，对digfacsum的贡献越大，这样n的位数也可以越小。所以应该从n的最小可能位数开始遍历，并且n的后面数字都是9，并不断减小9的个数，剩下的暴力。重新写程序来计算i=55以后的g[i]。
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
string str;
int maxsfn = 0;
LL len;
int sg[N];
string headofn[N];
LL numof9[N];
int L = 1;
/*
int dfs(int level, LL fn) {
if (level == 20) return 0;
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
*/
int expn;
int dfs(int level, LL fn) {
	if (level == L) {
		LL new_fn = fn;
		int new_sfn = 0;
		while (new_fn) {
			new_sfn += new_fn % 10;
			new_fn /= 10;
		}
		LL digsumN = 9 * (len - L);
		for (int i = 0; i < L; ++i) digsumN += str[i] - '0';
		//if(new_sfn >= left && new_sfn < right)
		// if (expn * 9 - 9 < new_sfn && new_sfn <= expn * 9 && sg[new_sfn] == 0) 
		string rstr = str;
		reverse(rstr.begin(), rstr.end());
		if (expn * 9 - 9 < new_sfn && new_sfn <= expn * 9 && sg[new_sfn] == 0)
		{
			sg[new_sfn] = digsumN;
			headofn[new_sfn] = rstr;
			numof9[new_sfn] = len - L;
			// cout << "sfn: " << new_sfn << " head of n: " << rstr << endl;		
		}
		//else {
		//	int len_old = numof9[new_sfn] + headofn[new_sfn].size();
		//	int len_now = len - L + str.size();
		//	if (len_now < len_old || ((len_now == len_old) && (rstr < headofn[new_sfn]))) {
		//		sg[new_sfn] = digsumN;
		//		headofn[new_sfn] = rstr;
		//		numof9[new_sfn] = len - L;
		//	}
		//}

		return 0;
	}
	for (int digit = 8; digit >= 0; --digit) {
		str += '0' + digit;
		LL new_fn = fn + factorial[digit];
		int new_sfn = 0;
		while (new_fn) {
			new_sfn += new_fn % 10;
			new_fn /= 10;
		}
		LL digsumN = 9 * (len - L);
		for (int i = 0; i < L; ++i) digsumN += str[i] - '0';
		//if(new_sfn >= left && new_sfn < right)
		// if (expn * 9 - 9 < new_sfn && new_sfn <= expn * 9 && sg[new_sfn] == 0) 
		string rstr = str;
		reverse(rstr.begin(), rstr.end());
		if (expn * 9 - 9 < new_sfn && new_sfn <= expn * 9 && sg[new_sfn] == 0)
		{
			sg[new_sfn] = digsumN;
			headofn[new_sfn] = rstr;
			numof9[new_sfn] = len - L;
			// cout << "sfn: " << new_sfn << " head of n: " << rstr << endl;		
		}
		//else {
		//	int len_old = numof9[new_sfn] + headofn[new_sfn].size();
		//	int len_now = len - L + str.size();
		//	if (len_now < len_old || ((len_now == len_old) && (rstr < headofn[new_sfn]))) {
		//		sg[new_sfn] = digsumN;
		//		headofn[new_sfn] = rstr;
		//		numof9[new_sfn] = len - L;
		//	}
		//}
		dfs(level + 1, fn + factorial[digit]);
		str.pop_back();
	}
}
int main() {
	factorial[0] = 1;
	memset(sg, 0, sizeof(sg));
	for (int i = 1; i < 10; ++i)
		factorial[i] = i * factorial[i - 1];

	//dfs(0, 0);

	// 计算g[150]
	//LL minLen = int(pow(10, (int)(150 / 9.0) + 1) / 27.0) + 1; // 27 = digsum(9!)
	// 150/9.0 = 16.667
	// 55/9.0 = 6.111
	// digfacsum至少有17位，从17个9开始遍历。16*9 = 144, 17*9 = 153, g[145]到g[150]

	for (expn = 17; expn > 1; --expn) {
		len = pow(10, expn) / factorial[9]; // n的长度，随着9的个数的减少而不断增长，因此能够保证 i 在 (9 * (expn - 1), 9 * expn] 中时，遇到的第一个g[i]就是最后的g[i]
		bool done = false;
		for (L = 1; !done; ++L) { // expn - L 个 9，与前面L个非9数字。
			cout << "L: " << L << endl;
			dfs(0, (len - L) * 27); // level, fn, 可能还需要len*27
			done = true;
			for (int i = (expn - 1) * 9 + 1; i <= expn * 9; ++i) {
				if (sg[i] == 0) {
					done = false;
					break;
				}
			}
		}
	}

	for (int i = 1; i <= 150; ++i) {
		cout << "i: " << i << " sg[i] " << sg[i] << " head of n: " << headofn[i] << " number of 9 " << numof9[i] << endl;
	}
	return 0;
}
// 1333579999999999999999999
/*
1: 1
2: 2
3: 5
4: 15
5: 25
6: 3
7: 13
8: 23
9: 6
10: 16
11: 26
12: 44
13: 144
14: 256
15: 36
16: 136
17: 236
18: 67
19: 167
20: 267
21: 349
22: 1349
23: 2349
24: 49
25: 149
26: 249
27: 9
28: 19
29: 29
30: 129
31: 229
32: 1229
33: 39
34: 139
35: 239
36: 1239
37: 13339
38: 23599
39: 4479
40: 14479
41: 2355679
42: 344479
43: 1344479
44: 2378889
45: 12378889
46: 133378889
47: 2356888899
48: 12356888899
49: 133356888899
50: 12245677888899
51: 34446666888899
52: 134446666888899
53: 12245578899999999
54: 123345578899999999
55: 1333666799999999999
*/
