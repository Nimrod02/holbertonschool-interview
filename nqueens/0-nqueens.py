#!/usr/bin/python3
import sys


def print_solutions(solutions):
    for solution in solutions:
        print(solution)


def is_safe(row, col, solution, N):
    for prev_row in range(row):
        if solution[prev_row] == col or \
           solution[prev_row] - prev_row == col - row or \
           solution[prev_row] + prev_row == col + row:
            return False
    return True


def solve_n_queens(row, solution, N, solutions):
    if row == N:
        solutions.append(solution[:])
        return
    for col in range(N):
        if is_safe(row, col, solution, N):
            solution[row] = col
            solve_n_queens(row + 1, solution, N, solutions)


def nqueens(N):
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = []
    solve_n_queens(0, [0]*N, N, solutions)
    formatted_solutions = [[(i, solution[i]) for i in range(N)]
                           for solution in solutions]
    print_solutions(formatted_solutions)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    nqueens(N)
