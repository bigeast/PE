/********************************
 * Author:			bigeast
 * Time:			2014-10-16
 * Description:		answer is 986262.
 * 很早之前做的，今天无意中看到，整理一下。
 * 当时的做法是很麻烦的，在一个个分解，后来不知道怎么算出的答案，忘了是不是运
 * 行了十几个小时。Thread里的一个方法，只需要O(nlogn)的复杂度，算出每一个小于N
 * 的数的约数个数。
 *
 * 其实也很简单了。。代码不过几行，看来筛法有时候还是特别有用的！
 * 要证明复杂度是O(nlogn)需要用到调和级数的近似值ln(n)。很神奇，nlog(n)在这里
 * 也能出现。
 ********************************/

#include <cstdio>
#include <cstring>

#define SZ 10000000
int numdiv[SZ + 1];

int main (int argc, char *argv[])
{
	memset(numdiv,0,sizeof(numdiv));
    for (int i = 1; i <= SZ; i++)
        for (int j = i; j <= SZ; j += i)
            numdiv[j]++;

    int ans = 0;
    for (int i = 1; i < SZ; i++)
        if (numdiv[i] == numdiv[i + 1])
            ans++;

    printf ("%d\n", ans);
    printf ("%d\n", numdiv[765547]);
    return 0;
}
