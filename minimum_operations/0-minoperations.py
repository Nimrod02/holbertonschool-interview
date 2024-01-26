#!/usr/bin/python3
""" module 0
"""


def minOperations(n):
    """method that calculates the fewest number of operations needed to result

    Args:
        n (int): number h in text file

    Returns:
        int: result of the operation
    """
    if n <= 1:
        return 0
    i = 2
    count = 0
    while i <= n:
        if n % i == 0:
            count += i
            n = n / i
        else:
            i += 1
    return count
