#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'luckBalance' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. 2D_INTEGER_ARRAY contests
#

def luckBalance(k, contests):
    # Write your code here
     
    important_luck = []
    total = 0
     
    for luck, important in contests:
        if(important == 1):
            important_luck.append(luck)
        else:
            total += luck
            
    important_luck.sort(reverse=True)
    
    for i in range(len(important_luck)):
        if i < k:
            total += important_luck[i]
        else:
            total -= important_luck[i]
    return total     
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    contests = []

    for _ in range(n):
        contests.append(list(map(int, input().rstrip().split())))

    result = luckBalance(k, contests)

    fptr.write(str(result) + '\n')

    fptr.close()
