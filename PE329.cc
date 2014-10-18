/********************************
 * Author:			bigeast
 * Time:			2014-10-18
 * Description:		AC. answer is 199740353/29386561536000. 1082nd
 *
 * 至少做了四个小时。
 * 其实早就做对了，只是忘了除以2^(len-1)。
 *
 * 基本过程就是，枚举起始点，然后枚举剩下行走方式，共有15-1=14种左右的选择，如
 * 果碰到边界要另外算。把得到的序列和参考序列相比，看有多少位相同，要乘2的相同
 * 位次幂的。因为相同的概率是2/3。
 ********************************/
#include <cstdio>
#include <cstring>
int prime_seive(int *p,int n){
	memset(p,1,sizeof(int)*n);
	p[0]=p[1]=0;
	for (int i = 0; i < n; i++) {
		if(p[i]) {
			for (int j = 2*i; j < n; j+=i) {
				p[j] = 0;
			}
		}
	}
	return 0;
}
const int n=500,len=15;
int isprime[n+1];
int r[len+1];
int main(int argc, const char *argv[])
{
	memset(r,0,sizeof(r));
	prime_seive(isprime,501);
	//char croaks[]="PP";
	char croaks[]="PPPPNNPPPNPPNPN";
	char ack[20];
	int idx,pos;
	puts("OK");
	for (int start = 1; start <= n ; start++) {
		memset(ack,0,sizeof(ack));
		if(isprime[start]) {
			ack[0] = 'P';
		}
		else {
			ack[0] = 'N';
		}
		for (int move = 0,tm; move < (1<<(len-1)); move++) {
			pos = start;
			int wrong = 0,right = 0;
			idx = 1;
			tm = move;
			for (int i = 0; i < len-1; i++,tm>>=1) {
				// move forward
				if(tm&1) {
					if(pos==500) pos--;
					else pos++;
				}
				// move backward
				else {
					if(pos==1)pos++;
					else pos--;
				}
				if(isprime[pos]) {
					ack[idx++] = 'P';
				}
				else {
					ack[idx++] = 'N';
				}
			}
			ack[len]=0;
			int t=0;
			while(croaks[t]!=0) {
				if(ack[t]==croaks[t]) right++;
				else wrong++;
				++t;
			}
			r[right]++;
		}
	}
	long long ans = 0;
	for (int i = 0; i < len+1; i++) {
	//		printf("%7d ",r[i]);
			ans+=r[i]*(1<<i);
	}
	//printf("%lld %lld\n",right,wrong);
	printf("%lld\n",ans);
	return 0;
}
