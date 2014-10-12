/********************************
 * Author:			bigeast
 * Time:			2014-10-11
 * Description:		AC. answer is 6531031914842725. 10923rd.
 * 全排列穷举。
 ********************************/

#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;
int g[5][3];
int set_g(int *a)
{
	g[0][1] = g[4][2] = a[0];
	g[0][2] = g[1][1] = a[1];
	g[1][0] = a[2];
	g[1][2] = g[2][1] = a[3];
	g[2][0] = a[4];
	g[2][2] = g[3][1] = a[5];
	g[3][0] = a[6];
	g[3][2] = g[4][1] = a[7];
	g[4][0] = a[8];
}
int check_g()
{
	int val = g[0][0]+g[0][1]+g[0][2];
	for (int i = 1,cnt; i < 5; i++) {
		cnt = 0;
		for (int j = 0; j < 3; j++) {
			cnt += g[i][j];
		}
		if(cnt!=val){
			return 0;
		}
	}
	return 1;
}
int getstr_g(char *str_g)
{
	int min_g = 100, min_i;
	for (int i = 1; i < 5; i++) {
		if(g[i][0]<min_g) {
			min_g = g[i][0];
			min_i = i;
		}
	}
	int idx = 0;
	for (int i = 0,ni; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			ni = (i+min_i)%5;
			if(g[ni][j]==10) {
				str_g[idx++] = '1';
				str_g[idx++] = '0';
			}
			else {
				str_g[idx++] = g[ni][j] + '0';
			}
		}
	}
	str_g[idx]=0;
	assert(idx==16);
	return 0;
}
int main(int argc, const char *argv[])
{
	g[0][0]=10;
	int a[]={1,2,3,4,5,6,7,8,9};
	char maxstr[20]="0",str_g[20];
	do {
		set_g(a);
		if(check_g()) {
			getstr_g(str_g);
			if(strcmp(str_g,maxstr)>0) {
				strcpy(maxstr,str_g);
			}
		}
	} while(next_permutation(a,a+9));
	puts(maxstr);
	return 0;
}
