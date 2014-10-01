#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int ans=0,ia,ib,ja,jb;
	double t,ns;
	for(int i=12;i<100;++i)
		for(int j=11;j<i;++j)
		{
			ns=(j+0.0)/i;
			ia=i/10;ib=i%10;
			ja=j/10;jb=j%10;
			if(ia==ib&&ja==jb)continue;
			if(ia==jb)t=(ja+0.0)/ib;
			else if(ib==ja)t=(jb+0.0)/ia;
			else continue;
			if(t-ns<1e-8&&ns-t<1e-8)
			{
				cout<<i<<"\t"<<j<<endl;
				++ans;
			}
		}
}
