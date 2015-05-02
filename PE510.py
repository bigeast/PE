#/********************************
# * Author:            bigeast
# * Time:            2015-05-03
# * Description:        AC.
# * Easy. Python "/" and "//" Error.
# ********************************/

import numpy as np


def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

N = 10 ** 9

M = int(np.sqrt(np.sqrt(N)) + 1) + 1
res = 0
for u in range(1, M):
    for v in range(1, u + 1):
        if gcd(u, v) == 1:
            b = (u * (u + v)) ** 2
            a = (v * (u + v)) ** 2
            if b <= N:
                c = (u * v) ** 2
                cnt = int(N // b)
                t1 = (a + b + c) * cnt * (cnt + 1) / 2
                t2 = (a + b + c) * cnt * (cnt + 1) // 2
                if int(t1) != int(t2):
                    print(a, b, c, cnt, (a + b + c) * cnt * (cnt + 1), t1, t2)
                res += int((a + b + c) * cnt * (cnt + 1) // 2)
print("Answer is", res)

#S(10^3) = 3072
#S(10^4) = 311709
#S(10^5) = 3148756421
#S(10^6) = 315177355539
#S(10^7) = 31526709841370
