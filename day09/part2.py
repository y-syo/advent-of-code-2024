import os
import os.path

def checksum(hdd):
    res = 0
    for i in range(len(hdd)):
        if hdd[i] != '.':
            res += i * int(hdd[i])
    return (res)

def has_free_size(hdd, j, size):
    block_size = 0
    while hdd[j] == '.':
        block_size += 1
        if block_size == size:
            return True
        j += 1
    return False

def main():
    file_path = "./input.txt"
    if os.path.isfile(file_path):
        content = open(file_path, "r").read()
    else:
        content = "2333133121414131402"

    hdd = []

    for i in range(len(content)):
        if i % 2 == 0:
            hdd.extend([i // 2 for x in range(int(content[i]))])
        else:
            hdd.extend(['.' for x in range(int(content[i]))])

    print(hdd)

    block_len = 1
    for i in range(len(hdd) - 1, -1, -1):
        if '.' not in [hdd[i], hdd[i - 1]] and int(hdd[i - 1]) == int(hdd[i]):
            block_len += 1
            continue
        
        for j in range(len(hdd[:i])):
            if has_free_size(hdd, j, block_len):
                for k in range(block_len):
                    hdd[i + k], hdd[j + k] = hdd[j + k], hdd[i + k]
                block_len = 1
                break
        block_len = 1

    print(checksum(hdd))



if __name__ == '__main__':
    main()
