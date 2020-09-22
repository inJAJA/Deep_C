a = [[1, 2, 3],[5, 3, 2],[2, 6, 3]]
b = [[1, 0],[0, 1]]

padding = [[0, 0, 0, 0, 0] for i in range(5)]

for i in range(2):
    for j in range(2):
        padding[1+i][1+j] = a[i][j]
print(padding)