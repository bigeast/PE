/********************************
 * Author:			bigeast
 * Time:			2014-10-14
 * Description:		AC. answer is 1258. 6061st.
 * Upgrade to Level 6!
 * 逆波兰表达式用来遍历所有的操作。
 * A(10,4)排列的遍历：用数1的个数的方法，得到组合C(10,4)，然后用STL中的
 * next_permutation函数得到所有排列。
 * 开始没理解题意，以为得到的数只能是正的，谁知道负的整数也算。
 ********************************/

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
int op[3],idxp,idx;
double digits[4],dig_cal[4],eps=1e-10;
const int INF=100000;
int len,maxlen=0,dig_res[4];
int pop(int n)
{
	int res = 0;
	while(n) {
		if(n&1){
			res++;
		}
		n>>=1;
	}
	return res;
}
int cal()
{
	double res,a,b;
	for (int i = 0; i < 4; i++) {
		dig_cal[i] = digits[i];
	}
	idx=3;
	idxp=2;
	while(idx>0) {
		b = dig_cal[idx];
		dig_cal[idx]=INF;
		idx--;
		a = dig_cal[idx];
		switch(op[idxp]) {
			case 0:
				res = a+b;
				break;
			case 1:
				res = a-b;
				break;
			case 2:
				res = a*b;
				break;
			case 3:
				if(b==0)return INF;
				res = a/b;
		}
		idxp--;
		dig_cal[idx] = res;
	}
	assert((int)res==(int)dig_cal[0]);
	double t = res-(int)res;
	//printf("%lf\n",res);
	if(t<eps && t>-eps) {
		return (int)res;
	}
	else return INF;
}
int main(int argc, const char *argv[])
{
	int vis[10000],res;
	for(int k=0,t;k<(1<<10);++k)
	{
		if(pop(k)!=4) {
			continue;
		}
		else {
			memset(vis,0,sizeof(vis));
			t = k;
			idx = 0;
			idxp = 3;
			int pos = 0;
			while(t)
			{
				if(t&1) {
					digits[idx++] = pos;
				}
				pos++;
				t >>= 1;
			}

			do 
			{
				for (int p0 = 0; p0 < 4; p0++) {
					op[0] = p0;
					for (int p1 = 0; p1 < 4; p1++) {
						op[1] = p1;
						for (int p2 = 0; p2 < 4; p2++) {
							op[2] = p2;
							res = cal();
							if(res !=INF) {
								vis[res>0?res:-res] = 1;
							}
						}
					}
				}
			} while(std::next_permutation(digits,digits+4));
			for (len = 1; len < INF; len++) {
				if(vis[len]==0) {
					break;
				}
			}

			len--;
			if(maxlen<len)
			{
				maxlen = len;
				for (int i = 0; i < 4; i++) {
					dig_res[i] = digits[i];
				}
			}
		}
	}
	puts("==========");
	printf("%d\n",maxlen);
	for (int i = 0; i < 4; i++) {
		printf("%d ",dig_res[i]);
	}
	putchar('\n');
	return 0;
}
