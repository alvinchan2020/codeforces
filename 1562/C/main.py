t = int(input())

for i in range(t):
    n = int(input())
    s = input()

    index = s.find("0")

    if index == -1:
        print("{} {} {} {}".format(1, n-1, 2, n))
    else:
        if (index + 1) <= int(n/2):
            print("{} {} {} {}".format(index + 1, n, index + 2, n))
        else:
            print("{} {} {} {}".format(1, index + 1, 1, index))
