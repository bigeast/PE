#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
//	int num[]={9,8,7,6,5,4,3,2,1,0};
	int num[]={0,1,2,3,4,5,6,7,8,9};
	long long cnt=0,t;
	do
	{
		if(num[0]==0)continue;
		if((100*num[7]+10*num[8]+num[9])%17==0)
		if((100*num[6]+10*num[7]+num[8])%13==0)
		if((100*num[5]+10*num[6]+num[7])%11==0)
		if((100*num[4]+10*num[5]+num[6])%7==0)
		if((100*num[3]+10*num[4]+num[5])%5==0)
		if((100*num[2]+10*num[3]+num[4])%3==0)
		if(num[3]%2==0)
		{
			for(int i=0;i<10;++i)cout<<num[i];
			cout<<"\t";
			t=0;
			for(int i=0;i<10;++i)
			{
				t*=10;
				t+=num[i];
			}
			cout<<cnt<<endl;
			cnt=cnt+t;
		}
	}while(next_permutation(num,num+10));
	cout<<cnt<<endl;
	return 0;
}
