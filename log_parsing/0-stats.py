#!/bin/bash

import sys

def print_stats(total_size, status_codes):
    print("Total file size:", total_size)
    for status_code in sorted(status_codes.keys()):
        if status_codes[status_code] > 0:
            print(status_code, ":", status_codes[status_code])

def parse_line(line):
    """
    Parse a log line and extract the IP address, status code, and file size.

    Args:
        line (str): The log line to parse.

    Returns:
        tuple: A tuple containing the IP address (str), status code (int), and file size (int).
               If the line cannot be parsed, None is returned for all values.
    """
    try:
        parts = line.split()
        ip_address = parts[0]
        status_code = int(parts[-2])
        file_size = int(parts[-1])
        return ip_address, status_code, file_size
    except:
        return None, None, None

def compute_stats():
    total_size = 0
    status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0

    try:
        for line in sys.stdin:
            ip_address, status_code, file_size = parse_line(line)
            if ip_address is not None:
                total_size += file_size
                if status_code in status_codes:
                    status_codes[status_code] += 1
            line_count += 1

            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        print_stats(total_size, status_codes)

compute_stats()
