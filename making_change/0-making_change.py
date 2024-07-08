#!/usr/bin/python3
"""
making_change module
"""


def make_change(coins, total):
    """
    Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount total.

    Args:
        coins (list of int): List of the values of the coins in your possession.
        total (int): The total amount of money you need to make change for.

    Returns:
        int: The fewest number of coins needed to meet the given amount total, or -1 if it's not possible.
    """
    coins.sort(reverse=True)

    current_sum = 0
    coin_count = 0
    i = 0
    num_coins = len(coins)

    while current_sum < total and i < num_coins:
        while coins[i] <= total - current_sum:
            current_sum += coins[i]
            coin_count += 1
            if current_sum == total:
                return coin_count
        i += 1

    return -1
