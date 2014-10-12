/********************************
 * Author:			bigeast
 * Time:			2014-10-12
 * Description:		AC. answer is 168. 5526th
 ********************************/

f(m,n) = {
ans = 0;
for(X=0,(n+1)/(m+1),ans+=binomial(n-(m-1)*X+1,2*X));
ans;
}
for(X=50,10000,if(f(50,X)>1e6,print(X);break));
