/********************************
 * Author:			bigeast
 * Time:			2014-10-20
 * Description:		AC. answer is 52852124. 2699th
 * 最长子串和。复杂度O(N)。
 * 主要是考虑如何控制序列的走向，比较容易出错。
 ********************************/

#include <cstdio>
/*
#define N 4
int tab[4][4]={
	{-2,5,3,2},{9,-6,5,1},{3,2,7,3},{-1,8,-4,8}
};
*/
#define N 2000
int tab[N+1][N+1];
int gen()
{
	int x,y,x1,y1,x2,y2,t;
	for (int i = 1; i <= N*N; i++) {
		x = i/N;
		y = i%N;
		if(i<=55) {
			t = (100003 - 200003*i + (long long)300007*i*i*i) % 1000000 - 500000;
		}
		else {
			x1 = (i-24)/N;
			y1 = (i-24)%N;
			x2 = (i-55)/N;
			y2 = (i-55)%N;
			t = (tab[x1][y1] + tab[x2][y2] + 1000000) % 1000000 - 500000;
		}
		tab[x][y] = t;
	}
	printf("%d %d\n",tab[0][10],tab[0][100]);
	return 0;
}
int main(int argc, const char *argv[])
{
	gen();
	long long maxsum = -10000000;
	long long f[N+1];
	for (int k = 0; k < N; k++) {
		// ==
		f[0] = tab[k][0];
		if(f[0]>maxsum)maxsum=f[0];
		for (int i = 1; i < N; i++) {
			if(f[i-1]>0) {
				f[i] = f[i-1] + tab[k][i];
			}
			else {
				f[i] = tab[k][i];
			}
			if(f[i] > maxsum) {
				maxsum = f[i];
			}
		}

		// ||
		f[0] = tab[0][k];
		if(f[0]>maxsum)maxsum=f[0];
		for (int i = 1; i < N; i++) {
			if(f[i-1]>0) {
				f[i] = f[i-1] + tab[i][k];
			}
			else {
				f[i] = tab[i][k];
			}
			if(f[i] > maxsum) {
				maxsum = f[i];
			}
		}

		// left down -> right up
		f[0] = tab[k][0];
		if(f[0]>maxsum)maxsum=f[0];
		for (int i = 1; i <= k; i++) {
			if(f[i-1]>0) {
				f[i] = f[i-1] + tab[k-i][i];
			}
			else {
				f[i] = tab[k-i][i];
			}
			if(f[i] > maxsum) {
				maxsum = f[i];
			}
		}
		f[0] = tab[N-1][N-1-k];
		if(f[0]>maxsum)maxsum=f[0];
		for (int i = 1; i <= k; i++) {
			if(f[i-1]>0) {
				f[i] = f[i-1] + tab[N-1-i][N-1-k + i];
			}
			else {
				f[i] = tab[N-1-i][N-1-k+i];
			}
			if(f[i] > maxsum) {
				maxsum = f[i];
			}
		}
		// left up -> right down
		f[0] = tab[0][N-1-k];
		if(f[0]>maxsum)maxsum=f[0];
		for (int i = 1; i <= k; i++) {
			if(f[i-1]>0) {
				f[i] = f[i-1] + tab[i][N-1-k + i];
			}
			else {
				f[i] = tab[i][N-1-k + i];
			}
			if(f[i] > maxsum) {
				maxsum = f[i];
			}
		}
		f[0] = tab[N-1-k][0];
		if(f[0]>maxsum)maxsum=f[0];
		for (int i = 1; i <= k; i++) {
			if(f[i-1]>0) {
				f[i] = f[i-1] + tab[N-1-k+i][i];
			}
			else {
				f[i] = tab[N-1-k+i][i];
			}
			if(f[i] > maxsum) {
				maxsum = f[i];
			}
		}
	}
	printf("%lld\n",maxsum);
	return 0;
}
