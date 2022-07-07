t = int(input())

for i in range(0, t):
    n = int(input())
    a = list(map(int, input().split()))
    
    while(len(a)!=0 and a[-1]==0):
        a.pop()

    a.reverse()
    while(len(a)!=0 and a[-1]==0):
        a.pop()

    if(len(a)==0):
        print(0)
    else:
        min_a = min(a)
        if min_a==0:
            print(2)
        else: 
            print(1)
    