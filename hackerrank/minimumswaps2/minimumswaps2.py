#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumSwaps function below.
def minimumSwaps(arr):
    num = 0
    length = len(arr)
    for i in range(0, length):
        while(i+1 != arr[i]):
            swapIndex = arr[i] -1
            
            arr[i], arr[swapIndex] = arr[swapIndex], arr[i]
            num+=1
    return num
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = minimumSwaps(arr)

    fptr.write(str(res) + '\n')

    fptr.close()
