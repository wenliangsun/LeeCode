import numpy as np

from collections import defaultdict
from sklearn.metrics import roc_curve
from sklearn.metrics import auc


def my_auc1(labels, preds, n_bins=100):
    '''
    AUC的计算：
    按照方法2计算，统计M * N对正负样本对中有多少组正样本score大于负样本score，
    当正负样本中score相等时，按照0.5计算，然后除以总的正负样本对。
    '''
    positive_len = sum(labels)  # 正样本数
    negative_len = len(labels) - positive_len  # 负样本数
    total = positive_len * negative_len  # 总的样本对
    pos_hist = [0 for _ in range(n_bins)]  # 正样本的桶
    neg_hist = [0 for _ in range(n_bins)]  # 负样本的桶
    bin_width = 1.0 / n_bins  # 每个桶的宽度，根据score的精度来计算
    for i in range(len(labels)):  # 将正负样本划入各个桶中
        nth_bin = int(preds[i] / bin_width)
        if labels[i] == 1:
            pos_hist[nth_bin] += 1
        else:
            neg_hist[nth_bin] += 1

    pre_neg = 0  # 累计之前的所有负样本
    satis_pair = 0
    for i in range(n_bins):
        # 当前满足的样本对分两部分：当前和正样本数量和之前累加的负样本构成的以及当前正负样本score一样的情况
        satis_pair += (pos_hist[i] * pre_neg + pos_hist[i] * neg_hist[i] * 0.5)
        pre_neg += neg_hist[i]

    return satis_pair / total  # 满足的样本对数除以总的样本对数


def my_auc2(labels, preds):
    '''
    按照方法3计算：
    1.对预测概率从高到低排序
    2.对每一个概率值设一个rank值（最高的概率的rank为n,第二高的为n-1）
    3.统计正样本的rank和
    4.除以M*N
    '''
    positive_len = sum(labels)  # 正样本数
    negative_len = len(labels) - positive_len  # 负样本数
    total = positive_len * negative_len  # 总的样本对
    f = list(zip(preds, labels))
    sf = sorted(f, key=lambda x: x[0]) # 排序
    d = defaultdict(list)
    for i, s in enumerate(sf): # 统计每个score的所有等级
        d[s[0]].append(i + 1)
    pos_sum = 0 # 正样本的等级之和
    for s in sf:
        if s[1] == 1:
            pos_sum += sum(d[s[0]]) / len(d[s[0]]) # score相同的时候取均值作为其等级
    return (pos_sum - positive_len * (positive_len + 1) / 2) / total # 按照公式计算


if __name__ == "__main__":
    labels = np.array([1, 0, 0, 0, 1, 0, 1, 0])
    preds = np.array([0.9, 0.8, 0.3, 0.1, 0.4, 0.9, 0.66, 0.7])
    fpr, tpr, thresholds = roc_curve(labels, preds, pos_label=1)
    print("sklearn: ", auc(fpr, tpr))
    print("my_auc1: ", my_auc1(labels, preds))
    print("my_auc2: ", my_auc2(labels, preds))
