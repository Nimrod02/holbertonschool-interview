#!/usr/bin/python3
"""
making_change module
"""


def makeChange(coins, total):
    """ given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount total

    Args:
        coins (list of int): list of the values of the coins in your possession
        total (int): the total amount of money you need to make change for

    Returns:
        int: return the fewest number of coins needed to meet
        a given amount total
    """
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    n = len(coins)
    result = 0
    i = 0
    while i < n and total > 0:
        if coins[i] <= total:
            total -= coins[i]
            result += 1
        else:
            i += 1
    if total != 0:
        return -1
    return result
