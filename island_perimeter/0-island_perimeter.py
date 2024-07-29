#!/usr/bin/python3
"""module - 0
"""

def island_perimeter(grid):
    """island_perimeter function to calculate the perimeter of an island

    Args:
        grid (array): 2D list of integers
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2
    return perimeter
