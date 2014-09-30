#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("22.in");
int fac(string t)
{
	int sum=0,len=t.length();
	for(int i=0;i<len;++i)
		sum+=t[i]-'A'+1;
	return sum;
}
int main()
{
	vector<string> a;
	string t;
	long long ans=0;
	while(fin>>t)
		a.push_back(t);
	sort(a.begin(),a.end());
	vector<string>::iterator it;
	for(it=a.begin();it!=a.end();++it)
		ans+=(it-a.begin()+1)*fac(*it);
	cout<<ans<<endl;
	return 0;
}
