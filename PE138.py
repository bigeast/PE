m, n = 4, 1
res = 0
for i in range(12):
    res += m**2 + n**2
    m, n = 4 * m + n, m
print("Answer is", res)
#4 1 8 15 17
#17 4 136 273 305
#72 17 2448 4895 5473
#305 72 43920 87841 98209
