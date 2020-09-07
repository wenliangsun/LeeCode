import numpy as np


def IoU(p1, p2):
    '''
    IoU的计算
    p1和p2:[x1, y1, x2, y2]
    '''
    xx1 = np.maximum(p1[0], p2[0])
    xx2 = np.minimum(p1[2], p2[2])
    yy1 = np.maximum(p1[1], p2[1])
    yy2 = np.minimum(p1[3], p2[3])

    w = np.maximum(0, xx2 - xx1)
    h = np.maximum(0, yy2 - yy1)

    inter = w * h
    area1 = (p1[2] - p1[0]) * (p1[3] - p1[1])
    area2 = (p2[2] - p2[0]) * (p2[3] - p2[1])

    return inter / (area1 + area2 - inter)


if __name__ == "__main__":
    p1 = [0, 0, 10, 10]
    p2 = [0, 0, 10, 10]
    iou = IoU(p1, p2)
    print(iou)