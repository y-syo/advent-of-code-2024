import os
import os.path

def main():
    res = 0
    valid = 1

    file_path = "./input.txt"
    if (os.path.isfile(file_path)):
        content = open(file_path, "r").read()
    else:
        content = "47|53\n97|13\n97|61\n97|47\n75|29\n61|13\n75|53\n29|13\n97|29\n53|29\n61|53\n97|53\n61|29\n47|13\n75|47\n97|75\n47|61\n75|61\n47|29\n75|13\n53|13\n\n75,47,61,53,29\n97,61,53,29,13\n75,29,13\n75,97,47,61,53\n61,13,29\n97,13,75,29,47"
    grid = content.split('\n')
    pages_part = grid[:grid.index("")]

    for line in grid[grid.index("") + 1:]:
        valid = 1
        for num in line.split(','):
            for page in pages_part:
                if num in page:
                    if page.split('|')[0] in line and page.split('|')[1] in line:
                        if page.split('|')[1] not in line.split(',')[line.split(',').index(page.split('|')[0]):]:
                            valid = 0
        if valid:
            res += int(line.split(',')[len(line.split(',')) // 2])

    print(res)

if __name__ == '__main__':
    main()
