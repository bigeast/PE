/********************************
 * Author:			bigeast
 * Time:			2014-10-12
 * Description:		AC. answer is 24702. 9096th.
 *
 * 开始用的STL的set容器，发现竟然不能简单地做集合的并，特别难用，于是还是用了
 * 位运算，方便又简单。但是注意(1<<i)代表数字i+1。
 *
 * 每个位置上都有三个限制，根据grid[i/3][j/3],row[i],col[j]求并，补集就是在位
 * 置(i,j)可以放置的合法数字集合。dfs时，选取合法集合大小最小的，可以加快速度
 * 。
 ********************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char sdk[10][10];
int topd,res=0;
unsigned grid[3][3],col[9],row[9];
unsigned alldig = (1<<9)-1,t;
int pop(unsigned n)
{
	int res=0;
	while(n) {
		if(n&1)res++;
		n>>=1;
	}
	return res;
}
int dfs()
{
	int mint=(1<<9)-1,minx,miny;
	unsigned t;
	for (int i = 0; i < 9; i++) {
		if(row[i]==alldig && col[i]==alldig) {
			if(i==8) {
				topd = (sdk[0][0]-'0')*100+(sdk[0][1]-'0')*10+sdk[0][2]-'0';
				printf("%d\n",topd);
				res += topd;
				for (int i = 0; i < 9; i++) {
					puts(sdk[i]);
				}
				return 0;
			}
		}
		else {
			break;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if(sdk[i][j]=='0') {
				t = grid[i/3][j/3] | row[i] | col[j];
				t = alldig - t;
				if(pop(t)<pop(mint)) {
					mint = t;
					minx = i;
					miny = j;
				}
			}
		}
	}
	for (int i = 0,m=1; i < 9; i++,m<<=1) {
		if(mint&m) {
			sdk[minx][miny] = i+'1';
			grid[minx/3][miny/3] += m;
			row[minx] += m;
			col[miny] += m;
			dfs();
			sdk[minx][miny] = '0';
			grid[minx/3][miny/3] -= m;
			row[minx] -= m;
			col[miny] -= m;
		}
	}
}
int main(int argc, const char *argv[])
{
	int T=50;
	char buf[50];
	freopen("p096_sudoku.txt","r",stdin);

	while(T--) {
		// Init.
		cin.getline(buf,20);
		puts(buf);
		memset(grid,0,sizeof(grid));
		memset(col,0,sizeof(col));
		memset(row,0,sizeof(row));
		for (int i = 0; i < 9; i++) {
			scanf("%s\n",sdk[i]);
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if(sdk[i][j]!='0') {
					t = sdk[i][j]-'0'-1;
					grid[i/3][j/3] |= (1<<t);
					row[i] |= (1<<t);
					col[j] |= (1<<t);
				}
			}
		}
		dfs();
	}
	printf("%d\n",res);
	return 0;
}
