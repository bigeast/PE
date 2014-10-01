//vis置零的位置放错了，一直出不来答案。学会了gdb单步跟踪。需要在g++ 时加上-g参数，也挺简单的。不过确实强大
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int flag=0;
	int i,j,k,t;
	bool vis[10];
	for(i=4;i>1;--i)
	{
		for(j=7;j>1;--j)
		{
			if(j==i)continue;
			for(k=7;k>1;--k)
			{
				if(k==i||k==j||k==5)continue;
				memset(vis,false,sizeof(vis));
				vis[i]=vis[j]=vis[k]=true;
				vis[9]=true;
				t=(9000+100*i+10*j+k);
				cout<<t<<" "<<2*t<<endl;
				t*=2;
				while(t)
				{
					if(vis[t%10]||t%10==0)break;
					vis[t%10]=true;
					t/=10;
				}
				if(t==0)
				{
					cout<<9<<i<<j<<k<<2*(9000+100*i+10*j+k)<<endl;
				
					return 0;
				}
			}
		}
	}
}
