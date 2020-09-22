image = [[10, 12, 10, 13], 
        [12, 12, 7, 5], 
        [7, 5, 5, 5], 
        [10, 10, 7, 8]]

maxpool = [[0, 0] for i in range(2)]

max = -(2^1000)
for h in range(2):
    for w in range(2):
        max = 0
        for kh in range(2):
            for kw in range(2):
                f = image[2*h+kh][2*w+kw]
                print('h:',2*h+kh, 'w:',2*w+kw) # 2를 곱해서 옆으로 넘어감
                if max < f:
                    max = f        
        print('max:', max)
        maxpool[h][w] = max

print(maxpool)
        
# 홀수 일떄
# tensorflow : 한번 더
# pytorch : 버림

                