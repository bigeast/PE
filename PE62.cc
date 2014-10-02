//#Sat, 07 Jan 2012 00:14:24 +0800
//C++速度还挺快的！
//主要用的是map，很方便，速度也不慢。还有，好久不用long long了。
//答案是5027^3，开始一直交的是5027...
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string,int> a;
	/*	a["bigeast"]=3;
		cout<<a["bigeast"];*/
	char s[50];
	long long k;
	for(long long i=1;i<10000;++i)
	{
		k=i*i*i;
		sprintf(s,"%lld",k);
		string st(s,s+strlen(s));
		sort(st.begin(),st.end());
// 012334556789 来自于最后注释掉的代码
		if(st=="012334556789")
		{
			cout<<i<<endl;
		}
		if(a.count(st)==0)
			a.insert(pair<string,int>(st,1));
		else 
		{
			a[st]++;
//			if(a[st]==5)cout<<i<<"\t"<<st<<endl;
		}
	}

/*	map<string,int>::iterator it;
	for(it=a.begin();it!=a.end();++it)
		if(it->second==5)cout<<it->first<<endl;*/
}
