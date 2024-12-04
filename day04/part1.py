# sorry i gave up.

import os
import os.path

target = "XMAS"

def count_horizontal(grid):
    res = 0
    for line in grid:
        res += line.count(target)
        res += line[::-1].count(target)
    return (res)

def count_vertical(grid):
    res = 0
    for i in range(len(grid[0])):
        res += (''.join([s[i] for s in grid if len(s) > i])).count(target)
        res += (''.join([s[i] for s in grid if len(s) > i]))[::-1].count(target)
    return (res)

def count_diagonal_left(grid):
    res = 0
    for i in range(len(grid)):
        res += (''.join([grid[x + i][x] for x in range(min(len(grid) - i, len(grid[0])))])).count(target)
        res += (''.join([grid[x + i][x] for x in range(min(len(grid) - i, len(grid[0])))]))[::-1].count(target)
    for i in range(1,len(grid[0])):
        res += (''.join([grid[x][x + i] for x in range(min(len(grid), len(grid[0]) - i))])).count(target)
        res += (''.join([grid[x][x + i] for x in range(min(len(grid), len(grid[0]) - i))]))[::-1].count(target)
    return (res)

def count_diagonal_right(grid):
    res = 0
    for i in range(len(grid)):
        res += (''.join([(grid[x + i][::-1])[x] for x in range(min(len(grid) - i, len(grid[0])))])).count(target)
        res += (''.join([(grid[x + i][::-1])[x] for x in range(min(len(grid) - i, len(grid[0])))]))[::-1].count(target)
    for i in range(1,len(grid[0])):
        res += (''.join([(grid[x][::-1])[x + i] for x in range(min(len(grid), len(grid[0]) - i))])).count(target)
        res += (''.join([(grid[x][::-1])[x + i] for x in range(min(len(grid), len(grid[0]) - i))]))[::-1].count(target)
    return (res)


def main():
    file_path = "./input.txt"
    if (os.path.isfile(file_path)):
        content = open(file_path, "r").read()
    else:
        content = "MMMSXXMASM\nMSAMXMSMSA\nAMXSXMAAMM\nMSAMASMSMX\nXMASAMXAMM\nXXAMMXXAMA\nSMSMSASXSS\nSAXAMASAAA\nMAMMMXMMMM\nMXMXAXMASX"
    grid = content.split('\n')
    print(count_horizontal(grid) + count_vertical(grid) + count_diagonal_left(grid) + count_diagonal_right(grid))

if __name__ == '__main__':
    main()
