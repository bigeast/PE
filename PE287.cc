/********************************
 * Author:			bigeast
 * Time:			2014-11-29
 * Description:		AC. answer is 313135496. 811th
 * 主要是判断一个块是否是全零或者全一。由于图案是一个圆的一部分（由于整数偏移
 * ，不是标准的圆），为凸集，因此只要四个角都相同，就可以决定整个块内的值。
 ********************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const long long N = 24;
const long long N0 = 1.415*(1<<(N-1));
//char pix[1<<N][1<<N]={{0,0,0,1},{0,0,1,0},{1,1,0,0},{1,1,0,0}};
//#define val(a,b) pix[a][b]
int val(long long x, long long y)
{
	//return (x-N/2)*(x-N/2) + (y-N/2)*(y-N/2) <= (1<<46);
	return x*x + y*y - (1<<N)*(x+y) + (pow(2,2*N-2)) <= 0;
}
int Rsame(int bitSize, int pos_x, int pos_y)
{
	if(bitSize == 0){
		return val(pos_x, pos_y);
	}
	int t = Rsame(bitSize - 1, pos_x, pos_y);
	if(Rsame(bitSize - 1, pos_x + (1<<(bitSize - 1)), pos_y)!=t || Rsame(bitSize - 1, pos_x, pos_y + (1<<(bitSize - 1)))!=t || Rsame(bitSize - 1, pos_x + (1<<(bitSize - 1)), pos_y + (1<<(bitSize - 1)))!=t)
	{
		return -1;
	}
	return t;
}
int same(int bitSize, int pos_x, int pos_y)
{
	int t = val(pos_x,pos_y);
	if(val(pos_x + (1<<(bitSize)) - 1, pos_y)!=t || val(pos_x, pos_y + (1<<(bitSize)) - 1)!=t || val(pos_x + (1<<(bitSize)) - 1, pos_y + (1<<(bitSize)) - 1)!=t)
	{
		return -1;
	}
	return t;
}
int encode(int bitSize, int pos_x, int pos_y)
{
	int rate = 0, t;
	if(bitSize < 0) return 0;
	t = same(bitSize, pos_x, pos_y);
	if(t==1 || (t==0 && (1<<bitSize)<=N0)) {
	//	printf("%d\n",bitSize);
		return 2;
	}
	else {
		rate ++;
		rate += encode(bitSize - 1, pos_x, pos_y);
		rate += encode(bitSize - 1, pos_x + (1<<(bitSize - 1)), pos_y);
		rate += encode(bitSize - 1, pos_x, pos_y + (1<<(bitSize - 1)));
		rate += encode(bitSize - 1, pos_x + (1<<(bitSize - 1)), pos_y + (1<<(bitSize - 1)));
	}
	return rate;
}
int main(int argc, const char *argv[])
{
	printf("%d\n",encode(N,0,0));
	return 0;
}
