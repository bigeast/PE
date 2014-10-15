\\/********************************
\\ * Author:			bigeast
\\ * Time:			2014-10-15
\\ * Description:		AC. answeris . 2396th.
\\ PARI/GP的现成函数。这样做总感觉是在作弊似的。
\\ 虽然速度有点慢，要5分钟。
\\ ********************************/

ans=0;for(n=1,64000000,a=sigma(n,2);if(issquare(a),ans+=n,if(n%10^6==0,print(n))));
ans
