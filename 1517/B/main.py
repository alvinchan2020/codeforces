from functools import reduce
from collections import deque

DEBUG = False

def tiredness(result):
    result = list(map(list, zip(*result)))
    return sorted(list(map(min, result)))

def solve(n: int, m: int, paths):
    sortedPaths = [deque(sorted(p)) for p in paths]
    allPaths = deque(sorted(reduce(list.__add__, paths)))

    if DEBUG:
        print("the shorted paths are:")
        print([allPaths[i] for i in range(m)])
        print("")

    result = []
    for i in range(m):
        choosed_path = []
        choosed_shortest = False 
        for i in range(n):
            if (not choosed_shortest) and (sortedPaths[i][0] != allPaths[0]):
                choosed_path.append(sortedPaths[i].pop())
            elif (not choosed_shortest) and (sortedPaths[i][0] == allPaths[0]):
                choosed_path.append(sortedPaths[i].popleft())
                allPaths.popleft()
                choosed_shortest = True 
            elif choosed_shortest: 
                choosed_path.append(sortedPaths[i].pop())
            else :
                raise Exception("unexcepted condition")
        result.append(choosed_path)

    result = list(map(list, zip(*result)))

    if DEBUG:
        print("the tiredness is the sum of:")
        print(tiredness(result))
        print("")

    return result


def main():
    t = int(input())

    for i in range(t):
        n, m = list(map(int, input().split()))
        paths = []
        for i in range(n):
            path = list(map(int, input().split()))
            paths.append(path)

        result = solve(n, m, paths)

        for p in result:
            print(" ".join(list(map(str, p))))

main()