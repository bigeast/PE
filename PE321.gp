/********************************
 * Author:			bigeast
 * Time:			2014-10-23
 * Description:		AC. answeris 2470433131948040. 821st
 USACO 4.1 shuffle M(n) = n(n+2) = k(k+1)/2 佩尔方程
 PE100，PE140，PE321都是佩尔方程。
 PQKRSL是从 http://www.alpertron.com.ar/QUAD.HTM 算出来的。
 ********************************/

P = 3
Q = 2
K = 3
R = 4
S = 3
L = 5
ans = 0
n = 1
k = 2
cnt = 0
{
	for(i=1,100,
			if(n>0,ans += n;cnt++;if(cnt==20,break));
			tn = P*n + Q*k + K;
			tk = R*n + S*k + L;
			print(n," ",k);
			n = tn;
			k = tk;
			)
}
n = 3;
k = 5;
cnt = 0;
{
	for(i=1,100,
			if(n>0,ans += n;cnt++;if(cnt==20,break));
			tn = P*n + Q*k + K;
			tk = R*n + S*k + L;
			print(n," ",k);
			n = tn;
			k = tk;
			)
}
print(ans)
/*
M(n) = (n+1)^2-1;
{
cnt = 0;
ans = 0;
for(n=1,10^50,
		t=2*M(n);
		st=sqrtint(t);
		if(st*(st+1)==t,
			cnt++;
			ans+=n;
			\\print(cnt," ",n," ",st," ",n/st*1.0);
			u = 2*n+2;
			v = 2*st+1;
			print(cnt," ",u," ",v," ",u/v*1.0);
			if(cnt==40,break)
		  )
   );
print("Answer is ",ans)
}
*/
