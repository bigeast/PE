#/********************************
# * Author:            bigeast
# * Time:            2015-05-02
# * Description:        AC.
# * http://en.wikipedia.org/wiki/Descartes%27_theorem
# ********************************/

from mpmath import mp


def dcurve(a, b, c):
    return a + b + c + 2 * mp.sqrt(a * b + b * c + c * a)


def dfs(a, b, c, depth):
    if depth == 10:
        return 0
    a, b, c = sorted([a, b, c])
    d = dcurve(a, b, c)
    if a == b == c:
        return 1 / d**2 + 3 * dfs(a, a, d, depth + 1)
    elif a == b != c:
        return 1 / d**2 + dfs(a, a, d, depth + 1) + 2 * dfs(b, c, d, depth + 1)
    elif a != b == c:
        return 1 / d**2 + dfs(b, c, d, depth + 1) + 2 * dfs(a, b, d, depth + 1)
    elif a != b != c:
        return 1 / d**2 + dfs(a, b, d, depth + 1) + dfs(a, c, d, depth + 1) + dfs(b, c, d, depth + 1)
    else:
        print("ERROR")

k0 = 1 + 2 / mp.sqrt(3)

print("Answer is %.8f" % (1 - (dfs(k0, k0, k0, 0) + 3 * dfs(k0, k0, -1, 0) + 3 / k0**2)))
