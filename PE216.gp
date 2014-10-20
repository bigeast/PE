\\/********************************
\\ * Author:			bigeast
\\ * Time:			2014-10-14
\\ * Description:		AC. answer is 5437849. 2419th
\\ Brute force... about 8 mins.
\\ ********************************/

ans = 0
for(n=2,5*10^7,if(isprime(2*n^2-1),ans++,if(n%10^6==0,print(n))));
print(ans)
