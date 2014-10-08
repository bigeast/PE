#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
long long MOD=10000000000;
int main()
{
	long long ans=1;
	for(int i=0;i<7830457;++i)
		ans*=2,ans%=MOD;
	ans*=28433;
	ans%=MOD;
	cout<<ans+1<<endl;
	return 0;
}
