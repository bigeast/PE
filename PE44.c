//暴力，二分，复习了bsearch
//#Fri, 09 Mar 2012 14:12:43 +0800
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *p1,const void *p2)
{
	return *(int*)p1-*(int*)p2;
}
const int N=10000;
int main()
{
	int pen[N];
	int sum,dif;
	int *s,*d;
	for(int i=1;i<N;++i)
		pen[i]=i*(3*i-1)/2;
	for(int i=1;i<N;++i)
		for(int j=i+1;(sum=pen[i]+pen[j])<=pen[N-1];++j)
		{
			dif=pen[j]-pen[i];
			if((d=(int *)bsearch(&dif,pen,N,sizeof(int),cmp))!=NULL)
			{
				if((s=(int *)bsearch(&sum,pen,N,sizeof(int),cmp))!=NULL)
				{
					printf("i:%d\tj:%d\ndif:%d\t%d\nsum:%d\t%d\n",i,j,dif,d-pen,sum,s-pen);
					return 0;
				}
			}
		}
}
