//开始只考虑到底数不能大于10,想当然以为指数也不能大于10.但其实不是的.
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	double lo[10];
	int ans=0;
	int i,j;
	for(i=1;i<10;++i)lo[i]=log10(i);
	for(i=1;i<30;++i)
	{
		double a=1-1.0/i;
		for(j=1;j<10;++j)
			if(lo[j]>=a)break;
		cout<<j<<endl;
		ans+=10-j;
	}
	cout<<ans<<endl;
	return 0;
}
