#!/usr/bin/python3

def isWinner(x, nums):
    def isPrime(n):
        if n <= 1:
            return False
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
        return True

    def countPrimes(n):
        count = 0
        for i in range(2, n + 1):
            if isPrime(i):
                count += 1
        return count

    total = countPrimes(max(nums))
    if total % 2 == 0:
        return False
    return True
