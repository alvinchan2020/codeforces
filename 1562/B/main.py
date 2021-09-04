def contains_1_4_6_8_9(n):
    if ("1" in n):
        return (True, "1")
    if ("4" in n):
        return (True, "4")
    if ("6" in n):
        return (True, "6")
    if ("8" in n):
        return (True, "8")
    if ("9" in n):
        return (True, "9")
    return (False, n)

double_nonprime = {"22", "25", "27", "32", "33", "35", "52", "55", "57", "72", "75", "77"}


t = int(input())

for i in range(0, t):
    k = int(input())
    n = input()

    if(k==1):
        print(1)
        print(n)
        continue

    if(k==2):
        contains, c = contains_1_4_6_8_9(n)
        if(contains):
            print(1)
            print(c) 
        elif n in double_nonprime:
            print(2)
            print(n)
        else:
            raise Exception("unexpected double digits n")
        continue 

    if(k>=3):
        contains, c = contains_1_4_6_8_9(n)
        if(contains):
            print(1)
            print(c) 
        else:
            k = 3
            n = n[0:3]
            print(2)
            if(n[1] + n[2] in double_nonprime):
                print(n[1] + n[2])
            elif(n[0] + n[1] in double_nonprime):
                print(n[0] + n[1])
            elif(n[0] + n[2] in double_nonprime):
                print(n[0] + n[2])
            else:
                raise Exception("unexpected double digits n")
