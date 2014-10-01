// 为什么没考虑8位或者更高位数的呢？ 20141002
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
bool isprime(int n)
{
	double a=sqrt(n+1.0);
	for(int i=2;i<a;++i)
		if(n%i==0)return false;
	return true;
}
int main()
{
	char a[]="7654321";
	int t=atoi(a),len=strlen(a);
	do
	{
		t=atoi(a);
		if(isprime(t))
		{
			cout<<t<<endl;				
			return 0;
		}
	}while(prev_permutation(a,a+len));
}
