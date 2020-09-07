import os
import math
import random
import copy
import itertools
import time
import queue
import heapq
from multiprocessing import Process, Queue, Pool, Manager


def worker():
    print("子进程执行...>>> pid = {}, ppid = {}".format(os.getpid(), os.getppid()))
    time.sleep(2)
    print("子进程执行完毕！>>> pid = {}, ppid = {}".format(os.getpid(), os.getppid()))

def worker2(args):
    print("子进程执行...>>> pid = {}, ppid = {}, 编号 = {}".format(os.getpid(), os.getppid(), args))
    time.sleep(2)
    print("子进程执行完毕！>>> pid = {}, ppid = {}, 编号 = {}".format(os.getpid(), os.getppid(), args))

'''
使用Process来实例对象
'''
def main():
    print("主进程执行。。。。。。。。。。")
    ps = []
    for i in range(3):
        p = Process(target=worker, name="worker"+str(i), args=())
        ps.append(p)
    # 开启进程
    for p in ps:
        p.start()
    # 阻塞进程
    for p in ps:
        p.join()
    
    print("主进程终止！")

def main2():
    print("主进程开始执行...>>> pid = {}".format(os.getpid()))
    ps = Pool(5) # 定义一个进程池，最大进程数是5
    for i in range(10):
        # ps.apply(worker2, args=(i,)) # 同步执行
        ps.apply_async(worker2, args=(i,)) # 异步执行
    
    ps.close()
    ps.join()
    print("主进程结束！")

if __name__ == "__main__":
    main2()