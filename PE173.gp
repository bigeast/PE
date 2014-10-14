\\ /********************************
\\ * Author:			bigeast
\\ * Time:			2014-10-14
\\ * Description:		AC. answer is 1572729. 5445th.
\\ ********************************/
\\ 枚举四个角的大小n，如果有剩余，再看是否能组成4n的倍数。N = 4*n^2 + 4nm
N = 10^6/4
ans = 0
for(n=1,1000,if(N-n^2<0,break,ans+=floor((N-n^2)/n)));
print(ans)
