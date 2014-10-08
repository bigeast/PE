#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <iostream>
#define N 50000000
using namespace std;
bool isprime(int n)
{
		double a=sqrt(n+1.0);
			for(int i=2;i<a;++i)
						if(n%i==0)return false;
				return n!=1;
}
int sq[7080],cu[400],sqsq[100],f2=0,f3=0,f4=0;
int main()
{
	int t;
	for(int i=2;i<7072;++i)
		if(isprime(i))
		{
			sq[f2]=i*i;
			if(i<369)cu[f3++]=i*sq[f2];
			if(i<=84)sqsq[f4++]=sq[f2]*sq[f2];
			f2++;
		}
	set<int> a;
	for(int i=0;i<f2;++i)
		for(int j=0;j<f3;++j)
			for(int k=0;k<f4;++k)
			{
				t=sq[i]+cu[j]+sqsq[k];
				if(t<N)a.insert(t);
			}
	printf("%d %d %d\n",f2,f3,f4);
	printf("%d\n",a.size());
	//set<int>::iterator it;
	//for(it=a.begin();it!=a.end();++it)
	//	cout<<*it<<endl;
	return 0;
}
