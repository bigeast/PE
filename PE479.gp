/********************************
 * Author:			bigeast
 * Time:			2014-10-21
 * Description:		AC. answer is 191541795. 313th
原来不用继续化简了，就开始暴力做！
 ********************************/

{
expmod(a,n,m) = 
	if(n==0,
			1,
			t = expmod(a,n\2,m);
			tt = t*t%m;
			if(n%2==1,
				tt*=a;tt%m,tt)
		);
}
{
M = 1000000007;
N = 1000000;
ans = 0;
for(k=1,N,
		a = (1-k^2)%M;
		b = expmod(a,N+1,M);
		[u,v,d] = gcdext(k^2,M);
		ans += ((a-b)*u)%M;
		);
print(ans%M)
}
