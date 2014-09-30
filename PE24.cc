#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char a[]="0123456789";
	int step=1;
	while(step<1e6)
	{
		next_permutation(a,a+10);
		step++;
	}
	cout<<a<<endl;
	return 0;
}
