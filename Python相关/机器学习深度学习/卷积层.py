import numpy as np

def conv2d(inpt, kernel, stride, padding):
    imH, imW = inpt.shape
    kH, kW = kernel.shape
    c_kh = int(kW // 2)
    c_kw = int(kH // 2)
    p_im = np.pad(inpt, ((padding, padding),(padding,padding)),mode='constant', constant_values=(0,0))
    o_W = int((imW + 2*padding - kW) // stride + 1)
    o_H = int((imH + 2*padding - kH) // stride + 1)
    res = np.zeros((o_W,o_H))
    for r in range(c_kh, imH - c_kh):
        for c in range(c_kw, imW - c_kw):
            cur_inpt = inpt[r - c_kh: r + c_kh, c - c_kw: c + c_kw]
            cur_out = cur_inpt * kernel
            conv_sum = np.sum(cur_out)
            res[r, c] = conv_sum
    
    return res

def conv2dDemo(img, kernel):
    ih, iw , ic = img.shape
    oh = (ih - 3) // 1 + 1
    ow = (iw - 3) // 1 + 1
    res = np.zeros((ih, iw))
    for r in range(1, ih - 1):
        for c in range(1, iw - 1):
            cur = img[r - 1 : r + 1, c - 1 : c + 1,:]
            out = cur * kernel
            s = np.sum(out)
            res[r,c] = s
    ans = res[1:ih-1, 1:iw-1]
    return ans


arr = np.array([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]])
kernel = np.array([[1,2],[3,4]])

res = conv2d(arr, kernel, 1, 0)

print(res)