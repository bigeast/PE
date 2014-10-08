#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	ifstream fin("triangles.txt");
	int x[3],y[3];
	int t[3];
	int cnt=0;
	for(int k=0;k<1000;++k)
	{
		for(int i=0;i<3;++i)
			fin>>x[i]>>y[i];
		for(int i=0,j;i<3;++i)	
		{
			j=(i+1)%3;
			t[i]=x[i]*y[j]-x[j]*y[i];
		}
		if((t[0]>0&&t[1]>0&&t[2]>0)||(t[0]<0&&t[1]<0&&t[2]<0))
			++cnt;
	}
	cout<<cnt<<endl;
	return 0;
}
