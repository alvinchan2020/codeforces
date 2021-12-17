def solve(a):
    a = sorted(a)
    reduction = 0
    minimas = []
    for ai in a:
        new_ai = ai - reduction
        minimas.append(new_ai)
        reduction += new_ai
    return max(minimas)


t = int(input())

for i in range(t):
    n = int(input())
    a = list(map(int, input().split(" ")))

    print(solve(a))
