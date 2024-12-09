import os
import os.path

def checksum(hdd):
    res = 0
    for i in range(len(hdd)):
        if hdd[i] != '.':
            res += i * int(hdd[i])
    return (res)

def main():
    file_path = "./input.txt"
    if (os.path.isfile(file_path)):
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

    for i in range(len(hdd) - 1, -1, -1):
        for j in range(len(hdd[:i])):
            if (hdd[j] == '.'):
                hdd[i], hdd[j] = hdd[j], hdd[i]
                break
    
    print(checksum(hdd))



if __name__ == '__main__':
    main()
