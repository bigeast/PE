/********************************
 * Author:			bigeast
 * Time:			2014-10-14
 * Description:		AC. answer is 9857164023. 1090th
 *
 * DFS。
 * 还是用位运算来做标记比较方便。但是要注意优先级，卡在(mask&(1<<m))!=0这条语
 * 句上好久，'&'的优先级似乎还没有'!='高。
 * 然后是题目没看仔细，要求的是使输出最大的输入的值，一开始只算输入的最大值了
 * 。
 * i3笔记本上的运行时间1min 14s。
 ********************************/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cassert>

char alldigs[]="9876543210";
//char alldigs[]= "9873602145";
int vis;
long long lst[10],idx;
long long ans = 0;
char ans_in[15];
int dig2num(char *dig,int n)
{
	int res = 0;
	for (int i = 0; i < n; i++) {
		res *=10;
		res += dig[i]-'0';
	}
	return res;
}
int check(char *digits)
{
	int t = digits - alldigs;
	if(t==10) {
		if(vis==(1<<10)-1 && idx>2){
			long long val=lst[0]*lst[1],t1,t2,d;
			for (int i = idx-1; i > 1; i--) {
				t1 = lst[i]*lst[0];
				t2 = t1;
				d=1;
				do
				{
					t2/=10;
					d*=10;
				} while(t2);
				val = d*val + t1;
			}
			if(val>ans) {
				printf("Input %s, bigger output: %lld\n",alldigs,val);
				ans = val;
				strcpy(ans_in,alldigs);
			}
			//		exit(0);
		}
	}
	else if(t == 0)
	{
		idx = 0;
		vis = 0;
		memset(lst,-1,sizeof(lst));
		for (int i = 1; i <= 10; i++) {
			lst[idx++] = dig2num(digits,i);
			if(lst[0]%10==0)continue;
			check(digits+i);
			--idx;
		}
	}
	else if(t < 10) {
		for (long long i = 1,m,a,at,flag,d2n; i <= 10-t; i++) {
			if(i>1&&digits[0]=='0')break;
			d2n = dig2num(digits,i);
			a = d2n*lst[0];
			flag = 1;
			// check if new product is allowed.
			int mask=0;
			at = a;
			do {
				m = at%10;
				if((mask&(1<<m))!=0||(vis&(1<<m))!=0) {
					flag = 0;
					break;
				}
				mask += 1<<m;
				at /= 10;
			}while(at);
			// new product is allowed.
			if(flag) {
				assert(vis^mask==vis+mask);
				vis ^= mask;
				lst[idx++] = d2n;
				check(digits+i);
				--idx;
				lst[idx]=-1;
				vis ^= mask;
			}
		}
	}
	else {
		printf("t %d\n",t);
		puts("Impossible!");
	}
    return 0;
}

int main(int argc, const char *argv[])
{
	do {
		check(alldigs);
	}
	while(std::prev_permutation(alldigs,alldigs+10));
	printf("Input: %s, largest output: %lld\n",ans_in,ans);
	return 0;
}
