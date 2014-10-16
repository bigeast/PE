#!/usr/bin/env python2
# -*- coding:utf-8 -*-
"""
/********************************
 * Author:            bigeast
 * Time:            2014-10-16
 * Description:        AC. answer is 18769. 5794th
 根据题目描述看不出相似对必须是互为排列，是从论坛上看到的。然后要注意前导零的
 情况要排除。
 判断一一对应，用set和条件语句很难写对，于是想到了用zip，这是第一次用到。
 ********************************/
"""
import numpy as np
def int2dig(n):
    lst = []
    while n:
        lst.append(n%10)
        n /= 10
    lst.reverse()
    return lst

f = file("p098_words.txt","r")
for w in f:
    wlist = w
wlist = [w.strip("\"") for w in wlist.split(',')]
wcnt = len(wlist)

sqlist = [n*n for n in xrange(1,int(np.sqrt(10**9)))]
sqdlist = [int2dig(sq) for sq in sqlist]
res = 0
for i in xrange(wcnt):
    for j in xrange(i+1,wcnt):
        a = wlist[i]
        b = wlist[j]
        if sorted(a) == sorted(b):
            for n in xrange(len(sqlist)):
                sq = sqlist[n]
                sqdigit = sqdlist[n]
                if len(sqdigit) == len(a):
                    # check if a could be map to a square
                    zp = zip(a,sqdigit);
                    La = len(set(a))
                    Lq = len(set(sqdigit))
                    Lz = len(set(zp))
                    if not (La == Lq and Lq == Lz):
                        continue

                    # check if b is a square
                    d = {}
                    for item in zp:
                        d[item[0]] = int(item[1])
                    # leading zero
                    if d[b[0]]==0:
                        continue
                    lst = 0
                    for c in b:
                        lst *= 10
                        lst += d[c]
                    if lst in sqlist:
                        print ''.join(a),''.join(b)
                        print sq,lst
                        print ""
                        if sq>res:
                            res = sq
                        if lst > res:
                            res = lst
print res
