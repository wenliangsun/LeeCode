'''
pytorch 写模型的大致流程
'''

import torch.nn as nn
import matplotlib.pyplot as plt
import torchvision
from torch.utils.data import Dataset, DataLoader
import torch.optim as optim
import torchvision.transforms as transforms
from torch.functional import F


class Net(nn.Module):
    '''
    构建模型
    '''
    def __init__(self):
        super(Net, self).__init__()
        self.conv1 = nn.Conv2d(3, 6, 5)
        self.pool = nn.MaxPool2d(2, 2)
        self.conv2 = nn.Conv2d(6, 16, 5)
        self.fc1 = nn.Linear(16 * 5 * 5, 120)
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10)
    
    def forward(self, x):
        x = self.pool(F.relu(self.conv1(x)))
        x = self.pool(F.relu(self.conv2(x)))
        x = x.view(-1, 16 * 5 * 5)
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = self.fc3(x)
        return x  



if __name__ == "__main__":
    trans = transforms.Compose([transforms.ToTensor(), transforms.Normalize((0.5,0.5,0.5),(0.5,0.5,0.5))]) # 预处理操作
    train = torchvision.datasets.MNIST(root='./data', train=True, download=True, transform=trans) # 加载数据
    train_loader = DataLoader(train, batch_size=4, shuffle=True) # 构建迭代器
    model = Net() # 实例化网络
    criterion = nn.BCEWithLogitsLoss() # 第一损失函数
    optimizer = optim.Adam(model.parameters()) # 选择优化器
    model.train() # 设置模型为训练模式
    for e in range(1000):
        t_loss = 0
        for i, (data, label) in enumerate(train_loader): # 遍历数据集
            optimizer.zero_grad() # pytorch梯度会自动累加，需要手动清空上次计算的梯度
            outputs = model(data) # 前向传播
            loss = criterion(outputs, label) # 计算损失
            loss.backward() # 损失反向传递
            optimizer.step() # 优化器更新一步参数
            t_loss += loss.item() # 累计损失


