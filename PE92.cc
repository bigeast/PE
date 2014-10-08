#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=10000000;
int next[N];
int gen(int n)
{
	int sum=0;
	do
	{
		sum+=(n%10)*(n%10);
		n/=10;
	}while(n);
	return sum;
}
int main()
{
	int ans=0;
	for(int i=1;i<N;++i)
	{
		next[i]=gen(i);
	}
	cout<<"Pre OK"<<endl;
	for(int i=1,t;i<N;++i)
	{
		t=i;
		while(1)
		{
			t=next[t];
			if(t==1||t==89)break;
		}
		if(t==89)++ans;
	}
	cout<<ans<<endl;
	return 0;
}
