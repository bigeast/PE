/********************************
 * Author:			bigeast
 * Time:			2014-10-15
 * Description:		AC. answer is 44043947822. 2970th
 * Easy.
 ********************************/

#include <cstdio>
#include <cmath>
int g(long long n)
{
	long long d = (1+sqrt(4*n+1))/2-1;
	long long a = log(d)/log(2);
	return 12345*a < d;
}
int main(int argc, const char *argv[])
{
	long long la = 1e10, rb = 1e11,mid;
	while(la<rb)
	{
		mid = (la-rb)/2+rb;
		if(g(mid)) {
			rb = mid-1;
		}
		else {
			la = mid+1;
		}
	}
	printf("%lld\n",la);
	return 0;
}
