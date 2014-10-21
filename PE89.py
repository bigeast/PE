#!/usr/bin/env python2
# -*- coding:utf-8 -*-
"""
/********************************
 * Author:            bigeast
 * Time:            2014-10-21
 * Description:        AC. answer is 743. 12173rd.
 ********************************/
罗马数字太难用了。规则看了好多遍。实现起来也不太好看。
阿拉伯人至少在数学符号上是胜过罗马的。。
"""
import numpy as np
R = {}
R['M'] = 1000
R['D'] = 500
R['C'] = 100
R['L'] = 50
R['X'] = 10
R['V'] = 5
R['I'] = 1


def r2n(roman):
    res = 0
    idx = 0
    length = len(roman)
    vis = np.zeros(length)
    for i in xrange(0,length-1):
        if vis[i] == 0:
            if R[roman[i+1]]<=R[roman[i]]:
                res = res + R[roman[i]]
            else:
                res += R[roman[i+1]] - R[roman[i]]
                vis[i+1] = 1
            vis[i] = 1
    if vis[length-1]==0:
        res += R[roman[length-1]]
    return res

def n2r(num):
    L = []
    while num>R['M']:
        num -= R['M']
        L.append('M')
    t1 = num/500
    t2 = num%500/100
    num %= 100
    if t1 ==0:
        if t2==4:
            L.append('C')
            L.append('D')
        else:
            while t2>0:
                L.append('C')
                t2 -= 1
    else:
        if t2==4:
            L.append('C')
            L.append('M')
        else:
            L.append('D')
            while t2>0:
                L.append('C')
                t2 -= 1
    
    t1 = num/50
    t2 = num%50/10
    num %= 10
    if t1 ==0:
        if t2==4:
            L.append('X')
            L.append('L')
        else:
            while t2>0:
                L.append('X')
                t2 -= 1
    else:
        if t2==4:
            L.append('X')
            L.append('C')
        else:
            L.append('L')
            while t2>0:
                L.append('X')
                t2 -= 1
    t1 = num/5
    t2 = num%5/1
    if t1 ==0:
        if t2==4:
            L.append('I')
            L.append('V')
        else:
            while t2>0:
                L.append('I')
                t2 -= 1
    else:
        if t2==4:
            L.append('I')
            L.append('X')
        else:
            L.append('V')
            while t2>0:
                L.append('I')
                t2 -= 1
    return L

f = file("p089_roman.txt","r")
ans = 0
for num in [num.strip('\n') for num in f]:
    n = r2n(num)
    r = n2r(n)
    print num,n,r
    if len(r)>len(num):
        print "ERROR"
    ans += len(num)-len(r)

print ans
