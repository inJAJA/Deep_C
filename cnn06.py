img_ch1 = [1, 4, 1, 5, 2, 0, 9, 2, 7]
img_ch2 = [3, 2, 5, 2, 1, 3, 4, 5, 0]

kernel_ch11 = [1, 0, 1, 1]
kernel_ch21 = [0, 1, 0, 1]
kernel_ch12 = [1, 0, 0, 1]
kernel_ch22 = [0, 1, 1, 0]
kernel_ch13 = [1, 1, 0, 0]
kernel_ch23 = [0, 0, 1, 0]

feature1 = [0, 0, 0, 0]
feature2 = [0, 0, 0, 0]
feature3 = [0, 0, 0, 0]

# image * kernel
# (3, 3, 2) * (2, 2, 2, 3) => (2, 2, 3)

img_size = int(len(img_ch1) ** 0.5)
kernel_size = int(len(kernel_ch11) ** 0.5)
feature_size = int(len(feature1) ** 0.5)

imgs = [img_ch1, img_ch2]
kernels = [kernel_ch11, kernel_ch21, kernel_ch12, kernel_ch22, kernel_ch13, kernel_ch23]
features = [feature1, feature2, feature3]

for h in range(feature_size):
    for w in range(feature_size):
        for f in range(len(features)):              # feature
            s = 0
            for i in range(len(imgs)):          # img
                img = imgs[i]
                kernel = kernels[2*f + i]
                feature = features[f]

                for kh in range(kernel_size):
                    for kw in range(kernel_size):
                        s += img[img_size*(h + kh) + w + kw] * kernel[kernel_size*kh + kw]
                
                feature[feature_size*h+w] = s

for f in range(3):
    print(features[f])             
                        # [11, 14, 22, 14]
                        # [7, 10, 12, 17]
                        # [7, 6, 11, 7]


def convolution(images, kernels):
    image_size = int(len(images[0])**0.5)
    kernel_size = int(len(kernels[0])**0.5)

    feature_num = int(len(kernels) / len(images))         # feature 개수
    feature_size = int((image_size-kernel_size) + 1)    # feature length
    features = [[0 for i in range(feature_size**2)] for j in range(feature_num)]
    # print(features)

    for h in range(feature_size):
        for w in range(feature_size):
            for f in range(len(features)):
                s = 0
                for i in range(len(images)):
                    feature = features[f]
                    img = images[i]
                    kernel = kernels[2*f + i]    
                    
                    for kh in range(kernel_size):
                        for kw in range(kernel_size):
                            s += img[img_size*(h + kh) + w + kw] * kernel[kernel_size*kh + kw]
                
                feature[feature_size*h + w] =s
    
    return features

features = convolution(imgs, kernels)
print(features)
'''
N : batch
H : height
W : width
kH : kernel height      # 진짜 kernel(filter) 갯수 : C * k
kW : kernel width
C : channel (in channel)
k : out-channel
P : output height
Q : output width

'''

      