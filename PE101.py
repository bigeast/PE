#!/usr/bin/env python2
# -*- coding: utf8 -*-
"""
" Author:            bigeast
" Time:            2014-10-14
" Description:        AC.  answer is 37076114526. 5805th
当初是尝试过用numpy的，但是好像精度不够，这次不知道为什么可以了。看来是对numpy
不了解。
Vandermonde 矩阵的逆有显式的公式，通过LU分解表示的。但是算起来有小数，不好处理
。
numpy里面也有matrix，但是文档里说推荐用array。

用列表展开生成Vandermonde矩阵，只是尝试了一下，没想到还真的可以！
"""
import numpy as np
def f(n):
    return (1+n**11)/(1+n);
y = [f(n) for n in xrange(1,11)]
res = 0
# 方程的元数从2到10，从1阶算到9阶近似。
for n in xrange(1,11):
    M = np.array([[i**j for j in xrange(n)] for i in xrange(1,n+1) ],dtype=np.int64)
    c = np.linalg.solve(M,y[:n])
    x = [(n+1)**i for i in xrange(n)]
    pred = np.dot(x,c);
    res += pred;

print int(res)
