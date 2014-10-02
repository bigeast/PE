/************************************************
Author:		bigeast
Time:		12/05/11 Fri 11:11:45 PM
State:		Passed #12/05/12 Sat 11:01:57 AM
Description:		
************************************************/
//不一定是按顺序来的
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct node
{
	int a,b;
	int p;
};
vector<node> Node;
vector<int> res;
int vis[10];
bool cmp(const node& n1,const node& n2)
{
	return n1.a<n2.a;
/*
	if(n1.a<n2.a)return true;
	else if(n1.a==n2.a)return n1.b<n2.b;
	else return false;
*/
}
int dfs(int step,int iniq,int seq)
{
	//if(step==3&&iniq==Node[seq].p)
	if(step==5)
	{
		node t;
		t.a=Node[res[5]].b,t.b=Node[res[0]].a;
		if(t.a==t.b)
		{
			int sum=0;
			for(int i=0,j,tv;i<res.size();++i)
			{
				j=res[i];
				tv=Node[j].a*100+Node[j].b;
				sum+=tv;
				cout<<tv<<" "<<Node[j].p<<endl;
			}
			cout<<sum<<endl;
			exit(0);
		}
	//	vector<node>::iterator lo=lower_bound(Node.begin(),Node.end(),t,cmp);
/*
		for(;(*lo).a==t.a;++lo)
		{
			if(!vis[(*lo).p]&&(*lo).b==t.b)
			{
				puts("OK");
				for(int i=0,j;i<res.size();++i)
				{
					j=res[i];
					cout<<Node[j].a*100+Node[j].b<<" "<<Node[j].p<<endl;
				}
			}
		}
*/

/*
		puts("Yes");
		cout<<res.size()<<endl;
		for(int i=0,j;i<res.size();++i)
		{
			j=res[i];
			cout<<Node[j].a*100+Node[j].b<<" "<<Node[j].p<<endl;
		}
*/
	//	exit(0);
	}
	vis[Node[seq].p]=1;
	vector<node>::iterator low;
	node tmp;
	int pos;
	tmp.a=Node[seq].b,tmp.b=0,tmp.p=-1;
	low=lower_bound(Node.begin(),Node.end(),tmp,cmp);
	for(;(*low).a==tmp.a;++low)
	{
		if(vis[(*low).p])
			continue;
		pos=low-Node.begin();
		res.push_back(pos);
		dfs(step+1,iniq,pos);
		res.pop_back();
	}
	vis[Node[seq].p]=0;
	return 0;
}
int main()
{
	int t;
	node tmp;
	for(int i=1;i<200;++i)
	{
		t=i*(i+1)/2;
		if(t<10000&&t>999)
		{
			tmp.a=t/100,tmp.b=t%100,tmp.p=0;
			if(tmp.b>9)Node.push_back(tmp);
		}
	//	s[0][f[1]++]=t,h[0][t/100]=t%100;
		t=i*i;
		if(t<10000&&t>999)
		{
			tmp.a=t/100,tmp.b=t%100,tmp.p=1;
			if(tmp.b>9)Node.push_back(tmp);
		}
			//s[1][f[2]++]=t,h[1][t/100]=t%100;
			t=i*(3*i-1)/2;
		if(t<10000&&t>999)
		{
			tmp.a=t/100,tmp.b=t%100,tmp.p=2;
			if(tmp.b>9)Node.push_back(tmp);
		}
			//s[2][f[3]++]=t,h[2][t/100]=t%100;
			t=i*(2*i-1);
		if(t<10000&&t>999)
		{
			tmp.a=t/100,tmp.b=t%100,tmp.p=3;
			if(tmp.b>9)Node.push_back(tmp);
		}
			//s[3][f[4]++]=t,h[3][t/100]=t%100;
			t=i*(5*i-3)/2;
		if(t<10000&&t>999)
		{
			tmp.a=t/100,tmp.b=t%100,tmp.p=4;
			if(tmp.b>9)Node.push_back(tmp);
		}
			//s[4][f[5]++]=t,h[4][t/100]=t%100;
			t=i*(3*i-2);
		if(t<10000&&t>999)
		{
			tmp.a=t/100,tmp.b=t%100,tmp.p=5;
			if(tmp.b>9)Node.push_back(tmp);
		}
			//s[5][f[6]++]=t,h[5][t/100]=t%100;
	}
	sort(Node.begin(),Node.end(),cmp);
	//for(int i=0;i<Node.size();++i)
	//	cout<<Node[i].a<<" "<<Node[i].b<<" "<<Node[i].p<<endl;
	for(int i=0;i<Node.size();++i)
	{
		memset(vis,0,sizeof(vis));
		res.push_back(i);
		dfs(0,Node[i].p,i);
		res.pop_back();
	}
}
