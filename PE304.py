# Fibonacci数列模M是周期序列，因为两个连续的数字唯一决定整个序列，共有M^2种可能，肯定会有重复。
# Pisano periods
# 本题中M在10^13量级，太大了，无法用暴力方法计算出周期。
# 其实只要知道f(10^14)和f(10^14+1) 模 M的值就能很容易计算出答案。
# 需要用到Fibonacci素数的性质？Fibonacci素数的下标也为素数，除了F_4 = 3。反之不成立。
# 哈，忘了用快速矩阵乘法！
# 2015-04-29 Wednesday 19:45:16
# AC 1200th

import gmpy
M = 1234567891011


def Mul(A, B):
    res = [[0, 0], [0, 0]]
    res[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % M
    res[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % M
    res[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % M
    res[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % M
    return res


def Power(A, n):
    if n == 0:
        return [[1, 0], [0, 1]]
    else:
        B = Power(A, n // 2)
        T = Mul(B, B)
        T = [[T[i][j] % M for j in range(2)] for i in range(2)]
        if n % 2 != 0:
            T = Mul(T, A)
            T = [[T[i][j] % M for j in range(2)] for i in range(2)]
        return T
cnt = 0
n = 10**14
A = [[0, 1], [1, 1]]
F = [0, 1]
res = 0
B = Power(A, n)
while cnt < 100000:
    nprime = int(gmpy.next_prime(n))
    B = Mul(B, Power(A, nprime - n))
    # B = Power(A, nprime)
    t = (F[0] * B[0][0] + F[1] * B[1][0]) % M
    res += t
    res %= M
    cnt = cnt + 1
    n = nprime
print(cnt, res)
