/********************************
 * Author:			bigeast
 * Time:			2014-10-20
 * Description:		AC. answer is 18613426663617118. 3958th.

 M = 10^n，要求的数是M的倍数加上p1，即 k*M + p1
 k*M + p1 = 0 (mod p2)
 k*M = p2 - p1 (mod p2)
 如果u*M = 1 (mod p2)，那么 k = u*(p2-p1) (mod p2)
 因此只需求得 M 模 p2 的逆元 u，然后 u*(p2-p1)*M + p1就是答案。注意u*(p2-p1)还
 要再模一次p2！
 这题另外坑人的一点是，p1<=10^6，但是最后一组p2是大于10^6的！
 PS：扩展欧几里德还是不能自己写出来。。
 ********************************/
{
P = primes(primepi(10^6)+1);
ans = 0;
for(n=4,#P,
		p1 = P[n-1];
		p2 = P[n];
		M = 10^((#digits(p1)));
		[u,v,d] = gcdext(M,p2);
		if(u<0,u=(u+p2)%p2);
		\\print("p1 ",p1," p2 ",p2," ",(u*(p2-p1))%p2*M+p1);
		ans += (u*(p2-p1))%p2*M + p1;
		);
	print(ans);
}
