/*
 * 开始以为是一个N皇后问题。前一段刚学过dfs+位操作做N皇后的，算到13，估计15暴力也能算。然后发现不对，题目没看清，这里没有N皇后中的对角线限制。
 * 然后去掉对角线限制，重新计算，15!=1.3e12，毕竟太大了。怎么优化呢？
 * 用shuffle算了1e10个排列，试图碰出最大值。在七台机器上分别跑，跑了一天了还没完，七台机器计算的当前最大值分别为： 13848 13892 13809 13906 13802 13857 13725，其中最大的是13906
 * 还算了下225个数最大的前15个数之和，是14644。
 * 还是要优化下的！但这是阶乘复杂度，怎么优化呢！想到了分治，把15x15分成7x7,8x8和剩下的两个矩形块，然后对7x7和8x8分别计算。为了确保最大的排列会分别出现在7x7和8x8中，可以对矩阵的行和列做循环移位，共15x15种移位方法，每种再继续计算一个7x7和一个8x8，这样复杂度可以降低到15^2*7!*8!=4.5e10。然后7x7和8x8也都可以用类似的方法进行分治，这样可以过样例，但最终得到的答案是13115（代码删了）。。肯定不对。
 * 然后盯着屏幕死看，有好多900+的数字，要是能基于这些数字进行搜索，会不会快些，什么高端的A*搜索试试？最后一想，可以统计下都有那些数字是900以上的，如果最大和不小于13906了，那平均值就已经是927，而且最大值也没超过1000，那最小值肯定不能太小呀！假设组成最大和的15个数中最小的是M，保守估计，就让其余的14个数字是所有255个数中的最大的14个，和是13682，那么M+13682>=13906，M>=224。因此小于224的数，确实可以不用考虑了。T取224的话，还是有太多非零元素，需要考虑1e17中情况，更加无法计算。**如果T不能取足够大，使得情况数减少，那么这种方法甚至是n^n的，比n!还大。** 幸运的是，用T=800试了一下，就得出了答案，而且是秒出。
 * 但这里其实有运气的成分。因为按道理，就应该用T=224。
 * AC之后，又试了下更小的T，证实确实答案正确，T=500的时候，需要遍历1.57e13中情况，但在两分钟内还是可以算出来的，结果还是13938.
 *
 * 好吧，本来不想看论坛里的解答的。。果然有更合理的解法，用的是dp，现在还没看懂！
 * 额，明白了，就是一个dp[N + 1][(1<<N)]大小的数组（从dp[0]不使用），第一维是行数，第二维存的是前面的行已经使用了那些列。利用dp[n][mask]更新dp[n+1]中，不与mask冲突的那些情况，即要更新使得 M & mask == 0 的dp[n+1][M]。最后的结果是dp[N][(1<<N) - 1]。
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <cstdio>
using namespace std;
const int N = 15;
int Matrix[N][N];
vector<int> v[N];
vector<int> seq;
unsigned mask;
int ans = 0;
int dfs(int n) {
	if (n == N) {
		int sum = 0;
		for (auto item : seq) sum += item;
		if (sum > ans) ans = sum;
		return 0;
	}
	for (int idx : v[n]) {
		if(mask & (1<<idx)) continue;
		mask ^= (1 << idx);
		seq.push_back(Matrix[n][idx]);
		dfs(n + 1);
		seq.pop_back();
		mask ^= (1 << idx);
	}
	return 0;
}
int main() {
	ifstream fin("p345_matrix_15.txt");
	int T = 820;
	int cnt = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			fin >> Matrix[i][j];
			printf(" %3d", Matrix[i][j] > T ? Matrix[i][j] : 0);
			// printf(" %3d", Matrix[i][j]);
			if (Matrix[i][j] > T)v[i].push_back(j);
		}
		cnt *= v[i].size();
		printf(" :%d\n", v[i].size());
	}
	//dfs(0);
	//cout << ans << endl;
	/* DP 方法 */
	int **dp = new int*[N + 1];
	for (int i = 0; i <= N; ++i) {
		dp[i] = new int[1 << N];
		memset(dp[i], 0, sizeof(int) * (1 << N));
	}// 直接分配栈内存会出错。
	for (int i = 0; i < N; ++i) {
		for (int mask = 0; mask < (1 << N); ++mask) {
			for (int b = 0; b < N; ++b) {
				if ((mask & (1 << b)) == 0)
					dp[i + 1][mask | (1 << b)] = max(dp[i + 1][mask | (1 << b)], dp[i][mask] + Matrix[i][b]);
			}
		}
	}
	cout << dp[N][(1 << N) - 1] << endl;

	return 0;
}
