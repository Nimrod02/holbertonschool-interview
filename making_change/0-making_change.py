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

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for x in range(coin, total + 1):
            dp[x] = min(dp[x], dp[x - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
