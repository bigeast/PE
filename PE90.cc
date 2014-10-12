/********************************
 * Author:			bigeast
 * Time:			2014-10-12
 * Description:		AC. answer is 1217. 5753rd.
 * 把6和9当成一样看待。
 ********************************/

#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;
char sq[10][3]= {"01", "04", "09", "16", "25", "36", "49", "64", "81",};
char stra[7],strb[7];
int pop(int n)
{
	int res = 0;
	while(n)
	{
		if(n&1){
			++res;
		}
		n>>=1;
	}
	return res;
}
// 在stra中寻找sq0；在strb中寻找sq1。
int findab(int &a,int &b,char sq0,char sq1)
{
	a = 0;
	b = 0;
	while(a<6 && sq0!=stra[a]) {
		++a;
	}
	while(b<6 && sq1!=strb[b]) {
		++b;
	}
	if((sq0=='6'||sq0=='9')&&a==6) {
		a = 0;
		while(a<6 &&  ('6'+'9'-sq0)!=stra[a]) {
			++a;
		}
	}
	if((sq1=='6'||sq1=='9')&&b==6) {
		b = 0;
		while(b<6 &&  ('6'+'9'-sq1)!=strb[b]) {
			++b;
		}
	}
}
int check()
{
	int a,b;
	for (int i = 0; i < 9; i++) {
		findab(a,b,sq[i][0],sq[i][1]);
		if(a==6||b==6) {
			findab(a,b,sq[i][1],sq[i][0]);
			if(a==6||b==6){
				return 0;
			}
		}
	}
	return 1;
}
int main(int argc, const char *argv[])
{
	if(check())
	{
		puts("YES");
	}
	//char alldig[12];
	int idx,num;
	int res=0;

	for (int i = 0,ti,tj; i < (1<<10); i++) {
		if(pop(i)==6) {
			for (int j = 0; j < (1<<10); j++) {
				if(pop(j)==6) {
					ti = i;
					tj = j;
					idx = 0;
					num = 0;
					while(ti)
					{
						if(ti&1) {
							stra[idx++] = '0'+num;
						}
						num++;
						ti >>= 1;
					}
					idx = 0;
					num = 0;
					while(tj)
					{
						if(tj&1) {
							strb[idx++] = '0'+num;
						}
						num++;
						tj >>= 1;
					}
					assert(idx==6);
					if(check()) {
						res++;
					}
				}
			}
		}
	}
	printf("%d\n",res/2);
	return 0;
}
