import tqdm

a = 1504170715041707
m = 4503599627370517
## m 是素数，因此满足 pow(x, m - 1, m) = 1，模逆就是 pow(x, m - 2, m)
m_inv = pow(a, m-2, m)

ans = [a]
minval = a
for n in tqdm.trange(2, 1000000000):
    t = (a*n) % m
    if t < minval:
        minval = t
        print(n, minval)
        ans.append(t)

    ## 小于1e8之后，改为使用模逆来求最小值
    if t < 1e8:
        break
        
## 求每一个小于 ans[-1] 的数的模逆
l = []
for i in tqdm.trange(1, ans[-1]):
    l.append((i * m_inv % m, i))
sl = sorted(l)

for item in sl:
    if item[1] < ans[-1]:
        ans.append(item[1])
        
print("Answer of PE700 is: ", sum(ans))
