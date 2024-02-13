#!/usr/bin/python3
import sys


"""Script to get stats from a request"""

i = 0
my_dict = {}
status_available = ['200', '301', '400', '401', '403', '404', '405', '500']
total_size = 0


def print_stats(total_size, my_dict):
    print("File size: {}".format(total_size))
    for key in sorted(my_dict):
        print("{}: {}".format(key, my_dict[key]))


try:
    for line in sys.stdin:
        line_split = line.split()

        try:
            file_size = line_split[-1]
            total_size += int(file_size)
        except (IndexError, ValueError):
            pass

        try:
            status_code = line_split[-2]
            if status_code in status_available:
                if status_code in my_dict:
                    my_dict[status_code] += 1
                else:
                    my_dict[status_code] = 1
        except (IndexError, ValueError):
            pass

        i += 1

        if i == 10:
            print_stats(total_size, my_dict)
            i = 0

    print_stats(total_size, my_dict)

except KeyboardInterrupt:
    print_stats(total_size, my_dict)
    raise
