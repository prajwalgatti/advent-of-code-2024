import numpy as np

def part1(arr1, arr2):
    arr1, arr2 = np.array(arr1), np.array(arr2)
    arr1.sort()
    arr2.sort()
    return np.sum(np.abs(arr2-arr1))

def part2(arr1, arr2):
    return sum([i*arr2.count(i) for i in arr1])

if __name__ == "__main__":
    with open("input.txt") as fp:
        data = [i.strip().split() for i in fp.readlines()]
    arr1 = [int(i[0]) for i in data]
    arr2 = [int(i[1]) for i in data]
    print(part1(arr1, arr2))
    print(part2(arr1, arr2))
