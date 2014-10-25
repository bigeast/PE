/********************************
 * Author:			bigeast
 * Time:			2014-10-25
 * Description:		AC. answer is 2944730. 4494th
 * 丑数。维护一个优先级队列，每次取出最小的一个数，乘以所有可用的素数后加入队
 * 列。之前一直没做出来是因为死循环，Q.pop的时候没有判断是不是已经empty，结果
 * 一直pop下去了。。
 * 注意priority_queue的定义方法。i7上17s，笔记本上应该是一分钟以内吧。
 ********************************/

#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
//const int Np = 25;
//const int N = 1e9;
const int Np = 25;
const int N = 1000000000;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int main(int argc, const char *argv[])
{
	priority_queue<int, vector<int>, greater<int> > Q;
	for (int i = 0; i < Np; i++) {
		Q.push(primes[i]);
	}
	long long t,ans=0,top;
	while(!Q.empty())
	{
		top = Q.top();
		ans++;
		do {
			Q.pop();
		}while(!Q.empty()&&Q.top()==top);
		for (int i = 0; i < Np; i++) {
			t = top*primes[i];
			if(t <= N) {
				Q.push(t);
			}
			else {
				break;
			}
		}
	//	printf("%lld %lld\n",top,ans);
	}
	printf("%lld\n",ans+1);
	return 0;
}
