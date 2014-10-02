#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#define max(a,b) a>b?a:b
using namespace std;

const int N=100;
int a[N][N];
ifstream fin("67.in");
int main()
{
	for(int i=0;i<N;++i)
		for(int j=0;j<=i;++j)
			fin>>a[i][j];
				
	for(int i=N-2;i>=0;--i)
		for(int j=0;j<=i;++j)
			a[i][j]+=max(a[i+1][j],a[i+1][j+1]);

	cout<<a[0][0]<<endl;
	return 0;
}

