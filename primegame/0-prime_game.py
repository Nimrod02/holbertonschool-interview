#!/usr/bin/python3
"""Module 0
"""

def isWinner(x, nums):
    """Determine the winner based on the number of prime numbers.

    Args:
        x (int): The number of rounds played.
        nums (list): A list of integers representing the available numbers.

    Returns:
        bool: True if the player with the largest number of prime numbers wins, False otherwise.
    """
    def isPrime(n):
        if n <= 1:
            return False
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
        return True

    total = sum(isPrime(i) for i in range(2, max(nums) + 1))
    return total % 2 != 0
