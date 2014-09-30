#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=1005;
int n,matrix[N][N];
bool vis[N][N];


//每个位置处至多有两个可扩展的方向：
//右>下；下>左；左>上；上>右
//所以若按1234的方法扩展，则第一次若能向1扩展则必须考虑4是否也能扩展，经过这个判断，条件语句的顺序才符合真实优先顺序
//（实际优先顺序是一个环，不能拓扑排序，但由于每次只需要比较其中两个，所以还是可以排个序）

void BFS()
{
	memset(vis,false,sizeof(vis));
	int r=1001*1001,tx,ty;
	tx=ty=1;
	matrix[1][1]=r;
	vis[1][1]=true;
	while(1)
	{
		
		if(!matrix[tx][ty+1]&&!vis[tx][ty+1])//右
		{
			if(!matrix[tx-1][ty]&&!vis[tx-1][ty])//上
				{matrix[tx-1][ty]=--r;vis[tx-1][ty]=true;tx--;}//上优于右
			else {matrix[tx][ty+1]=--r;vis[tx][ty+1]=true;ty++;}
		}
		else if(!matrix[tx+1][ty]&&!vis[tx+1][ty])//下,右优于下，但已经考虑过了
		{matrix[tx+1][ty]=--r;vis[tx+1][ty]=true;tx++;}
		else if(!matrix[tx][ty-1]&&!vis[tx][ty-1])//左
		{matrix[tx][ty-1]=--r;vis[tx][ty-1]=true;ty--;}
		else if(!matrix[tx-1][ty]&&!vis[tx-1][ty])//上
		{matrix[tx-1][ty]=--r;vis[tx-1][ty]=true;tx--;}
		
		else break;
	}
}
int main()
{
	memset(matrix,0,sizeof(matrix));
	for(int i=0;i<=1002;++i)//外围置1
	{
		matrix[0][i]=matrix[i][0]=1;
		matrix[1002][i]=matrix[i][1002]=1;
	}
	BFS();
	long long sum=0;
	for(int i=1;i<=1001;++i)
		sum+=matrix[i][i]+matrix[i][1002-i];
	sum--;
	cout<<sum<<endl;
	return 0;
}
