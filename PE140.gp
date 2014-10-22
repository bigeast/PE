/********************************
 * Author:			bigeast
 * Time:			2014-10-23
 * Description:		AC. answer is 5673835352990. 2338th
 生成函数，容易计算。
 佩尔方程。先根据暴力算出的前几个最小解，判断有多少组。这道题一共有六组。前三
 十个那就是每组取前5个。注意根据迭代算出来的还有负数解，要忽略掉。
 ********************************/
/*
f(n) = 5*n^2+14*n+1;
{
	for(n=1,1000,t=f(n);k=sqrtint(t);if(k^2==t,print(n," ",k," ")))
}
*/
P = -9;
Q = -4;
K = -14;
R = -20;
S = -9;
L = -28;

f(n) = 5*n^2+14*n+1;

ans = 0;

n = 2;
k = 7;
cnt = 0;
{
	for(i=1,100,
			if(n>0,ans += n;cnt++;print(n," ",k);if(cnt==5,break));
			tn = P*n + Q*k + K;
			tk = R*n + S*k + L;
			n = tn;
			k = tk;
			)
}

n = 5;
k = 14;
cnt = 0;
{
	for(i=1,100,
			if(n>0,ans += n;cnt++;print(n," ",k);if(cnt==5,break));
			tn = P*n + Q*k + K;
			tk = R*n + S*k + L;
			n = tn;
			k = tk;
			)
}

n = 21;
k = 50;
cnt = 0;
{
	for(i=1,100,
			if(n>0,ans += n;cnt++;print(n," ",k);if(cnt==5,break));
			tn = P*n + Q*k + K;
			tk = R*n + S*k + L;
			n = tn;
			k = tk;
			)
}
\\print(ans)
n = 42;
k = 97;
cnt = 0;
{
	for(i=1,100,
			if(n>0,ans += n;cnt++;print(n," ",k);if(cnt==5,break));
			tn = P*n + Q*k + K;
			tk = R*n + S*k + L;
			n = tn;
			k = tk;
			)
}

n = 152;
k = 343;
cnt = 0;
{
	for(i=1,100,
			if(n>0,ans += n;cnt++;print(n," ",k);if(cnt==5,break));
			tn = P*n + Q*k + K;
			tk = R*n + S*k + L;
			n = tn;
			k = tk;
			)
}

n = 296;
k = 665;
cnt = 0;
{
	for(i=1,100,
			if(n>0,ans += n;cnt++;print(n," ",k);if(cnt==5,break));
			tn = P*n + Q*k + K;
			tk = R*n + S*k + L;
			n = tn;
			k = tk;
			)
}
print(ans)
/*
2 7 
5 14 
21 50 
42 97 
152 343 
296 665
*/
