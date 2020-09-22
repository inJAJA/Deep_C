a = [1, 2, 3, 5, 3, 2, 2, 6, 3]
b = [1, 0, 1, 1]
c = [0, 0, 0, 0]

# c = [9, 7, 13, 12]

# def convolution(a, b, a_length, b_length): # 정사각형
#     for 
#     return c

image_size = int(len(a)**0.5)    # 3 : 행방향 이동
kernel_size = int(len(b)**0.5)    # 2
feature_size = int(len(c)**0.5)    # 2

for h in range(feature_size):
    for w in range(feature_size):
        s = 0
        for kh in range(kernel_size):
            for kw in range(kernel_size):
                s += a[ image_size*(h + kh) + w + kw ] * b[ kernel_size * kh + kw ]
                print('a:', h*3 + w + kh*3 + kw, 'b:', kh*2 + kw)
                # print('a:', image_size*(h + kh) + w + kw, 'b:', kernel_size * kh + kw)
        c[feature_size * h + w] = s
        print('---------')

print(c)    # [9, 7, 13, 12]