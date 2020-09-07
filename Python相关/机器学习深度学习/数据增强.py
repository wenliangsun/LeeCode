import cv2
import numpy as np
import torch.nn as nn
from torch.functional import F

img = cv2.imread("D:/Projects/WinProject/C++Algorithm/Python相关/深度学习框架/demo.jpg")

print(img)

img1 = img[:, ::-1, :]
img2 = img[::-1, :, :]
img3 = cv2.resize(img, (512, 512))

cv2.imshow("img", img)
cv2.imshow("img1", img1)
cv2.imshow("img2", img2)
cv2.imshow("img3", img3)
cv2.waitKey(0)


bboxes = np.random.rand(10, 4)
x1 = bboxes[:, 0]
y1 = bboxes[:, 1]
x2 = bboxes[:, 2]
y2 = bboxes[:, 3]
w = np.maximum(0, x2 - x1)
h = np.maximum(0, y2 - y1)
area = w * h
mxarea = np.max(area)
print(mxarea)

# print(bboxes)
