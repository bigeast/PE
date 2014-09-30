#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
int main()
{
	set<int> a;
	bool vis[10],vis1[10];
	for(int i=2000,t;i<10000;++i)
	{
		t=i;
		memset(vis,false,sizeof(vis));
		vis[0]=true;
		while(t)
		{
			if(vis[t%10])break;
			vis[t%10]=true;
			t/=10;
		}
		if(t>0)continue;
		for(int j=2;j<10;++j)
		{
			if(i%j==0&&!vis[j]&&i/j>1000)
			{
				memcpy(vis1,vis,sizeof(vis));
				vis1[j]=true;
				t=i/j;
				while(t)
				{
					if(vis1[t%10])break;
					vis1[t%10]=true;
					t/=10;
				}
				if(t==0)
				{
					cout<<j<<"\t"<<i/j<<"\t"<<i<<endl;
					a.insert(i);
				}
			}
		}
	}
	for(int i=10;i<100;++i)
	{
		if(i%10==0||i%10==i/10)continue;
		for(int j=100,t;i*j<10000;++j)
		{
			memset(vis,false,sizeof(vis));
			vis[i%10]=vis[i/10]=true;
			vis[0]=true;
			t=j;
			while(t)
			{
				if(vis[t%10])break;
				vis[t%10]=true;
				t/=10;
			}
			if(t==0)
			{
				t=i*j;
				while(t)
				{	
					if(vis[t%10])break;
					vis[t%10]=true;
					t/=10;
				}
				if(t==0)
				{
					cout<<i<<"\t"<<j<<"\t"<<i*j<<endl;
					a.insert(i*j);
				}
			}
		}
	}
	set<int>::iterator it;
	int sum=0;
	for(it=a.begin();it!=a.end();++it)
	{
		sum+=*it;
		//cout<<*it<<endl;
	}
	cout<<"Sum is "<<sum<<endl;
	return 0;
}
