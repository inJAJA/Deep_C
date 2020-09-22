a = [[1, 2, 3],[5, 3, 2],[2, 6, 3]]
b = [[1, 0],[0, 1]]
c = [[0, 0],[0, 0]]

for h in range(2):
    for w in range(2):
        s = 0
        for kh in range(2):
            for kw in range(2):
                s+= a[h+kh][w+kw] * b[kh][kw]
        c[h][w] = s

print(c)