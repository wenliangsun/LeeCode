import numpy as np

def nms(bboxes, scores, thresh):
    '''
    nms的计算
    '''
    x1 = bboxes[:, 0]
    y1 = bboxes[:, 1]
    x2 = bboxes[:, 2]
    y2 = bboxes[:, 3]
    order = scores.argsort()[::-1] # 对得分排序
    areas = (x2 - x1 + 1) * (y2 - y1 + 1)
    keep = []
    while order.size() > 0:
        i = order[0]
        keep.append(i)
        xx1 = np.maximum(x1[i], x1[order[1:]])
        yy1 = np.maximum(y1[i], y1[order[1:]])
        xx2 = np.minimum(x2[i], x2[order[1:]])
        yy2 = np.minimum(y2[i], y2[order[1:]])

        w = np.maximum(0, xx2 - xx1)
        h = np.maximum(0, yy2 - yy1)
        inter = w * h

        ious = inter / (areas[i] + areas[order[1:]] - inter)
        inds = np.where(ious <= thresh)[0]
        order = order[inds + 1]
    return keep
