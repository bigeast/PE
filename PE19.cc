#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;

int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
int howday(int x,int y,int z)
{
	int n=0;
	if((x%4==0&&x%100!=0)||x%400==0)month[1]=29;
	else month[1]=28;
	for(int i=0;i<y-1;++i)
		n+=month[i];
	n+=z;
	return n;
}

int main()
{
	int cnt=0,s;
	for(int i=1901,t;i<=2000;++i)
	{
		s=i-1;
		for(int j=1;j<=12;++j)
		{
			if((t=(s+s/4-s/100+s/400+howday(i,j,1))%7)==0)
			{
				++cnt;
				cout<<cnt<<"\t"<<i<<"\t"<<j<<endl;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
