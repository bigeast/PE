/********************************
 * Author:			bigeast
 * Time:			2014-10-16
 * Description:		AC. answer is 2269. 5399th.
 题意：
 (1+x)(1+2x)(1+3x)...(1+15x)，求x幂次小于等于15/2=7的各项系数之和S。
 为了使玩家赢钱值的期望R*S/16!<1，即赌场不亏本，则设置的奖励R应为16!/S
 ********************************/
N = 15;
a=1;
for(n=1,N,a*=(1+n*x));
ans = 0;
if(N%2==0,cor=-1,cor=0);
for(win=0,N/2+cor,ans+=polcoeff(a,win));
res = floor(factorial(N+1)/ans);
print(res);
