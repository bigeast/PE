/********************************
 * Author:			bigeast
 * Time:			2014-10-09
 * Description:		AC. answer is 44680. 3641st
 * 这题真是有意思！
 * 是在写的过程中发现只需要遍历9!种状态然后根据末位数字分段就行了。但是开始以
 * 为末位数字只能是1,3,7,9，后来才发现2可以单独出来，5也可以！幸亏题目给出的
 * 例子里面把2和5都列了出来！
 * 如果一开始就把2和5考虑进来，则最多可以有6个元素，代码会更长。
 ********************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define is1379(a) ((a)!='5'&&((a)-'0')%2==1)
int isprime(int n)
{
	int a = sqrt(n+1);
	for (int i = 2; i <=a; i++) {
		if (n%i==0) {
			return 0;
		}
	}
	return n!=1;
}
int c2int(char *digits,int len)
{
	char *p = digits;
	int res = 0;
	for (int i = 0; i < len; i++) {
		res *= 10;
		res += digits[i]-'0';
	}
	return res;
}
int solve(char *digits, int len)
{
	int res;
	res = 0;
	int a,b,c,d,res1,res2,res3,res4;
	res1 = res2 = res3 = res4 = 0;
	do {
		if(is1379(digits[len-1]))
		{
			// {}
			a = c2int(digits,len);
			if(isprime(a)) {
				++res1;
			}
			// {}{}
			for (int i = 0; i < len-1; i++) {
				if (is1379(digits[i])) {
					a = c2int(digits,i+1);
					if(isprime(a))
					{
						b = c2int(digits+i+1,len-1-i);
						if(isprime(b))
						{
						   	++res2;
	//						printf("%d %d\n",a,b);
						}

						// {}{}{}
						for (int j = i+1; j < len-1; j++) {
							if (is1379(digits[j])) {
								b = c2int(digits+i+1,j-i);
								if(isprime(b)) {
									c = c2int(digits+j+1,len-1-j);
									if(isprime(c))
										++res3;

									// {}{}{}{}
									for (int k = j+1; k < len-1; k++) {
										if(is1379(digits[k])) {
											c = c2int(digits+j+1,k-j);
											if(isprime(c)) {
												d = c2int(digits+k+1,len-1-k);
												if(isprime(d))
													++res4;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	} while(std::next_permutation(digits,digits+len));
	printf("%d %d %d %d\n",res1,res2,res3,res4);
	res = res1+res2/2+res3/6+res4/24;
	printf("%d\n",res);
	return res;
}
int main(int argc, const char *argv[])
{
	int res = 0;
	char digits[] = "123456789";
	res += solve(digits,9);
	char digits2[] = "13456789";
	res += solve(digits2,8);
	char digits5[] = "12346789";
	res += solve(digits5,8);
	char digits25[] = "1346789";
	res += solve(digits25,7);
	printf("%d\n",res);
	return 0;
}
