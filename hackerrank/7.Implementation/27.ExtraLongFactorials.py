#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the extraLongFactorials function below.
def extraLongFactorials(n):
    result = 1
    fact = []
    if n == 1:
        return 1
    if n == 2:
        return 2
    if n > 3:
        for i in range(1, n+1):
            result = result * i 
        return result
    
    
if __name__ == '__main__':
    n = int(input())

    result = extraLongFactorials(n)
    print(result)
