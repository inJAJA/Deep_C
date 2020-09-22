image = [[3, 2, 4, 5, 6],
        [4, 5, 6, 1, 2],
        [2, 3, 1, 0, 2],
        [4, 2, 1, 4, 3],
        [3, 4, 7, 2, 1]]

kernel = [[1, 1],[0, 1]]

feature = [[0, 0, 0, 0] for i in range(4)]

for h in range(4):
    for w in range(4):
        s = 0
        for kh in range(2):
            for kw in range(2):
                s+= image[h+kh][w+kw] * kernel[kh][kw]
                # print(image[h+kh][w+kw])
                # print(kernel[kh][kw])
                # print('#################')
        feature[h][w] = s

print(feature)
  
