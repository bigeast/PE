#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;
ifstream fin("11.in");
ofstream fout("11.out");

int a[20][20];
int main()
{
	int maxv=0,t;
	for(int i=0;i<20;++i)
		for(int j=0;j<20;++j)
		{
			fin>>a[i][j];
		}
	for(int i=0;i<20;++i)
		for(int j=0;j+3<20;++j)
		{
			t=a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3];
			if(t>maxv)maxv=t;
		}
	for(int j=0;j<20;++j)
		for(int i=0;i+3<20;++i)
		{
			t=a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j];
			if(t>maxv)maxv=t;
		}

	for(int i=3;i<20;++i)
	{
		for(int j=0;j<17;++j)
		{
			t=a[i][j]*a[i-1][j+1]*a[i-2][j+2]*a[i-3][j+3];
			if(t>maxv)maxv=t;
		}
		for(int k=3;k<20;++k)
		{
			t=a[i][k]*a[i-1][k-1]*a[i-2][k-2]*a[i-3][k-3];
			if(t>maxv)maxv=t;
		}
	}
	cout<<maxv<<endl;
	return 0;
}	
