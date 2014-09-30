#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;

ofstream fout("14.out");
typedef long long LL;
LL pro(LL n)
{
	LL ans=0;
	while(n!=1)
	{
		if(n&1)n=3*n+1;
		else n/=2;
		++ans;
	}
	return ans;
}
int main()
{
	LL maxlen=0,mloc,len;
	for(LL i=1e6;i>1e4;--i)
	{
		len=pro(i);
		if(len>maxlen)
		{
			maxlen=len;
			mloc=i;
		}
	}
	fout<<maxlen<<"\t"<<mloc<<endl;
	return 0;
}

