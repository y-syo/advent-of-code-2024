# sorry i gave up.

import os
import os.path

target = "XMAS"

def check_x(grid, x, y):
    if (x not in range(1, len(grid[0]) - 1) or y not in range(1, len(grid) - 1)):
        return (0)
    str = grid[y - 1][x - 1] + grid[y + 1][x + 1]
    if (str not in "SMS"):
        return (0)
    str = grid[y + 1][x - 1] + grid[y - 1][x + 1]
    if (str not in "SMS"):
        return (0)
    return (1)

def count_xmas(grid):
    res = 0
    for y in range(len(grid)):
        for x in range(len(grid[0])):
            if (grid[y][x] == 'A'):
                res += check_x(grid, x, y)
    return (res)


def main():
    file_path = "./input.txt"
    if (os.path.isfile(file_path)):
        content = open(file_path, "r").read()
    else:
        content = "MMMSXXMASM\nMSAMXMSMSA\nAMXSXMAAMM\nMSAMASMSMX\nXMASAMXAMM\nXXAMMXXAMA\nSMSMSASXSS\nSAXAMASAAA\nMAMMMXMMMM\nMXMXAXMASX"
    grid = content.split('\n')
    print(count_xmas(grid))

if __name__ == '__main__':
    main()
