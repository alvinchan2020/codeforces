
def solve(r, c, s):
    pos = [1, 1]
    pos_range = {"U": 1, "D": 1, "L": 1, "R": 1}
    for command in s:
        # execute command
        if command == "R":
            pos[1] += 1
            pos_range["R"] = max(pos_range["R"], pos[1])
        elif command == "L":
            pos[1] -= 1
            pos_range["L"] = min(pos_range["L"], pos[1])
        elif command == "U":
            pos[0] -= 1
            pos_range["U"] = min(pos_range["U"], pos[0])
        elif command == "D":
            pos[0] += 1
            pos_range["D"] = max(pos_range["D"], pos[0])
        else:
            raise NotImplementedError()

        # check range
        if (pos_range["D"] - pos_range["U"] + 1 > r) or (pos_range["R"] - pos_range["L"] + 1 > c):
            # roll back
            if command == "R":
                pos[1] -= 1
                pos_range["R"] -= 1
            elif command == "L":
                pos[1] += 1
                pos_range["L"] += 1
            elif command == "U":
                pos[0] += 1
                pos_range["U"] += 1
            elif command == "D":
                pos[0] -= 1
                pos_range["D"] -= 1
            else:
                raise NotImplementedError()

            break

    # calc starting point
    starting_pos = [2-pos_range["U"], 2-pos_range["L"]]
    return starting_pos


t = int(input())

for i in range(t):
    r, c = list(map(int, input().split(" ")))
    s = input()

    result = solve(r, c, s)
    print(result[0], result[1])
