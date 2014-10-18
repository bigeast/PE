/********************************
 * Author:			bigeast
 * Time:			2014-10-18
 * Description:		AC. answer is CAGBIHEFJDK. 831st.
 *
 * 纯粹模拟就好了。蛋疼的是要算两遍才能算出来答案，第一遍只是算maximix的值(
 * 其实也可以在第一遍算的时候就记录个数)。
 * 11!=4e7，因此还好，算一遍一份多钟，如果知道maximix的值是19后，得到答案只要
 * 14s
 ********************************/

#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
int len = 11;
int Nth = 2011;
char train[]="ABCDEFGHIJK",*pos;
//int len = 6;
//int Nth =10;
//char train[]="ABCDEF",*pos;
using namespace std;
int main(int argc, const char *argv[])
{
	char tmp[20];
	int cnt,next;
	int maxcnt = 19;
	int timer=0;
	// calculate maximix, which is 19
/*
	do {
		cnt = 0;
		next = 0;
		strcpy(tmp,train);
		do {
			while(next<len-1 && tmp[next] == 'A' + next) {
				++next;
			}
			if(next<len-1) {
				pos = find(tmp+next,tmp+len,'A' + next);
				assert(*pos!=0);
				if(tmp[len-1]!=*pos) {
					reverse(pos,tmp+len);
					++cnt;
				}
				reverse(tmp+next,tmp+len);
				++cnt;
			}
		} while(next<len-1);
		if(cnt>maxcnt) {
			maxcnt = cnt;
		}
		timer++;
		if(timer%(1<<16)==0) {
			printf("%d\n",timer);
		}
	} while(next_permutation(train,train+len));
	puts("Pre Cal OK");
*/
	int nth=0;
	timer = 0;
	do {
		cnt = 0;
		next = 0;
		strcpy(tmp,train);
		do {
			while(next<len -1 && tmp[next] == 'A' + next) {
				++next;
			}
			if(next<len-1) {
				pos = find(tmp+next,tmp+len,'A' + next);
				assert(*pos!=0);
				if(tmp[len-1]!=*pos) {
					reverse(pos,tmp+len);
					++cnt;
				}
				reverse(tmp+next,tmp+len);
				++cnt;
			}
		} while(next<len-1);
		if(cnt==maxcnt) {
			++nth;
			if(nth==Nth) 
			{
				puts(train);
				return 0;
			}
		}
		timer++;
		if(timer%(1<<16)==0) {
			printf("%d\n",timer);
		}
	}while(next_permutation(train,train+len));
	printf("%d\n",maxcnt);
	return 0;
}
