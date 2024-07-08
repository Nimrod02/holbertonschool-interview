#!/usr/bin/python3
"""
making_change module
"""


def makeChange(coins, total):
    """ Given a pile of coins of different values,
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
    sum = 0
    i = 0
    counter = 0
    num_coins = len(coins)
    while sum < total and i < num_coins:
        while coins[i] <= total - sum:
            sum += coins[i]
            counter += 1
            if sum == total:
                return counter
        i += 1
    return -1
