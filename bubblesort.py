import random
import numpy
def bubbleSort(nums):
    for i in range(len(nums)-1):    # 这个循环负责设置冒泡排序进行的次数
        for j in range(len(nums)-i-1):  # ｊ为列表下标
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1], nums[j]
    return nums
#s生成随机数
def random_int_list(start, stop, length):
    start, stop = (int(start), int(stop)) if start <= stop else (int(stop), int(start))
    length = int(abs(length)) if length else 0
    random_list = []
    for i in range(length):
        random_list.append(random.randint(start, stop))
    return random_list
def main():
    start=input("随机数起始：")
    stop=input("随机数末尾：")
    length=int(input("随机数长度："))
    print('生成的随机数为：')
    print(random_int_list(start,stop,length))
    print('冒泡排序的结果为：')
    print(bubbleSort(random_int_list(start,stop,length)))
if __name__=='__main__':
    main()