image =[[0, 0, 0, 0, 0, 0], # image size = (4, 4) padding = (1, 1), stride = (3, 3)
        [0, 3, 2, 4, 5, 0], # if stride =(2, 2) ...??
        [0, 2, 3, 1, 0, 0],
        [0, 4, 2, 1, 4, 0],
        [0, 3, 4, 7, 2, 0],
        [0, 0, 0, 0, 0, 0]]

kernel = [[1, 1, 0], [0, 1, 0], [1, 0, 1]] # kernel_size = (3, 3)

feature = [[0, 0] for i in range(2)]    # feature map = (2, 2) // if stride =(2, 2), size ?

# feature map

# firest 2D
# second 1D
## if you want, 1D first okay

stride = 3 # stride

# first 
for h in range(2):
    for w in range(2):
        s = 0
        for kh in range(3):
            for kw in range(3):
                s += image[h*stride+kh][w*stride+kw] * kernel[kh][kw]
                # print('image h:', h*stride+kh, 'w:', w*stride+kw, 'kh:', kh, 'kw', kw)
                # print('-----------')
        feature[h][w] = s
print(feature)  # [[6, 6],[7, 7]]

# second
image = [0, 0, 0, 0, 0, 0, 
        0, 3, 2, 4, 5, 0, 
        0, 2, 3, 1, 0, 0, 
        0, 4, 2, 1, 4, 0, 
        0, 3, 4, 7, 2, 0, 
        0, 0, 0, 0, 0, 0]

kernel = [1, 1, 0, 0, 1, 0, 1, 0, 1]

feature = [0, 0, 0, 0]

image_size = int(len(image)**0.5)       # 6
kernel_size = int(len(kernel)**0.5)     # 3
feature_size = int(len(feature)**0.5)   # 2

for h in range(feature_size):
    for w in range(feature_size):
        s = 0
        for kh in range(kernel_size):
            for kw in range(kernel_size):
                s += image[image_size*(h*stride + kh)+ w*stride + kw] * kernel[kernel_size*kh + kw]
                print('img:',image_size*(h*stride + kh)+ w*stride + kw, 'k:', kernel_size*kh + kw )
        feature[feature_size*h + w] = s
        print(feature_size*h +w)

print(feature)

# 함수 
def convolution(image, kernel, stride=1):
    img_len = int(len(image)**0.5)
    kernel_len = int(len(kernel)**0.5)

    feature_len = int((img_len - kernel_len) / stride + 1)
    feature = [0 for i in range(feature_len**2)]

    for h in range(feature_len):
        for w in range(feature_len):
            s = 0
            for kh in range(kernel_len):
                for kw in range(kernel_len):
                    s += image[img_len*(h*stride + kh) + w*stride + kw] * kernel[kernel_len*kh + kw]
            feature[feature_len*h + w] = s
    
    return feature

feature = convolution(image, kernel)
print(feature)