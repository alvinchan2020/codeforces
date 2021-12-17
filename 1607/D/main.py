def solve(a, c):
    ac = sorted(zip(c, a))
    for i in range(len(ac)):
        if (ac[i][0] == 'B' and ac[i][1] >= i+1) or (ac[i][0] == 'R' and ac[i][1] <= i+1):
            continue
        else:
            return False
    return True


t = int(input())


for i in range(t):
    n = int(input())
    a = list(map(int, input().split(" ")))
    c = list(input())

    result = solve(a, c)

    if result == True:
        print("YES")
    else:
        print("NO")
