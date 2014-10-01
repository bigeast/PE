#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=1002;
int sq[N];
int main()
{
	int maxi,maxv=0,a,b,c,cnt;
	for(int i=0;i<N;++i)
		sq[i]=i*i;

	cout<<maxi<<"\t"<<maxv<<endl;
	for(int i=10;i<=1000;++i)
	{
		cnt=0;
		for(c=i/3+1;c<i;++c)
		{
			for(a=1;a<(i-c)/2;++a)
				if(sq[a]+sq[i-c-a]==sq[c])++cnt;
		}
		if(cnt>maxv)maxi=i,maxv=cnt;
	}
	cout<<maxi<<"\t"<<maxv<<endl;
	return 0;
}
