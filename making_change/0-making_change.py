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

    newVal = total + 1
    store = {0: 0}

    for i in range(1, total + 1):
        store[i] = newVal

        for coin in coins:
            current = i - coin
            if current < 0:
                continue

            store[i] = min(store[current] + 1, store[i])

    if store[total] == total + 1:
        return -1

    return store[total]
