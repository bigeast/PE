#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=1002;
bool vis[N];
int pos[N];
int main()
{
	int maxi,maxv=0;
	for(int i=2,r,step;i<1000;++i)
	{
		r=1;
		step=0;
		memset(vis,false,sizeof(vis));
		memset(pos,0,sizeof(pos));
		while(1)
		{
			++step;
			r*=10;
			if(r<i)continue;
			r%=i;
			if(r==0)break;
			if(!vis[r])vis[r]=true,pos[r]=step;
			else
			{
				if(step-pos[r]>maxv)
				{
					maxi=i;
					maxv=step-pos[r];
				}
				break;
			}
		}
	}
	cout<<maxi<<"\t"<<maxv<<endl;
	return 0;
}
