# passed test 1 and test 2
# TLE on test 3

# This code is too messy, I'll just rewrite in DFS

from collections import Counter
from itertools import chain

NLOOP_MARK = -1
loop_counter = 0
loop_start_pos = ()


def is_valid(r, c, n, m):
    return r >= 0 and r < n and c >= 0 and c < m


def is_start(r, c, n, m, board_commands):
    assert(is_valid(r, c, n, m))

    if (is_valid(r-1, c, n, m) and board_commands[r-1][c] == "D") or \
        (is_valid(r+1, c, n, m) and board_commands[r+1][c] == "U") or \
        (is_valid(r, c-1, n, m) and board_commands[r][c-1] == "R") or \
            (is_valid(r, c+1, n, m) and board_commands[r][c+1] == "L"):
        return False
    else:
        return True


def execute_command(r, c, n, m, board_commands):
    assert(is_valid(r, c, n, m))

    command = board_commands[r][c]
    if command == "L":
        c -= 1
    elif command == "R":
        c += 1
    elif command == "D":
        r += 1
    elif command == "U":
        r -= 1
    else:
        raise Exception()

    return r, c


def is_end(r, c, n, m, board_commands):
    new_r, new_c = execute_command(r, c, n, m, board_commands)
    if is_valid(new_r, new_c, n, m):
        return False
    else:
        return True


def mark_re(r, c, n, m, board_commands, board_marks, steps_set):
    global loop_counter
    global loop_start_pos

    if not is_valid(r, c, n, m):
        return NLOOP_MARK

    if board_marks[r][c] is not None and board_marks[r][c] > 0:
        return NLOOP_MARK

    if (r, c) in steps_set:
        loop_counter += 1
        loop_mark = loop_counter
        board_marks[r][c] = loop_mark
        loop_start_pos = (r, c)
        return loop_mark

    steps_set.add((r, c))

    next_r, next_c = execute_command(r, c, n, m, board_commands)
    next_mark = mark_re(next_r, next_c, n, m, board_commands,
                        board_marks, steps_set)

    steps_set.remove((r, c))

    if next_mark == NLOOP_MARK:
        board_marks[r][c] = NLOOP_MARK
        return NLOOP_MARK
    else:
        # deal loops
        board_marks[r][c] = next_mark
        if loop_start_pos == (r, c):
            return NLOOP_MARK
        else:
            return next_mark


def solve(n: int, m: int, board_commands):
    board_marks = [[None]*m for i in range(n)]

    # mark loops
    for i in range(n):
        for j in range(m):
            if board_marks[i][j] is not None:
                continue
            steps_set = set()
            mark_re(i, j, n, m, board_commands,
                    board_marks, steps_set)

    # count loop size
    counter = Counter(chain.from_iterable(board_marks))
    if NLOOP_MARK in counter:
        counter.pop(NLOOP_MARK)

    # find max length loop
    max_length = 0
    max_start_r, max_start_c = 0, 0
    for i in range(n):
        for j in range(m):
            if board_marks[i][j] > 0:
                loop_length = counter[board_marks[i][j]]
                if loop_length > max_length:
                    max_length = loop_length
                    max_start_r, max_start_c = i, j
    # find start pos then count length
    for i in range(n):
        for j in range(m):
            if not is_start(i, j, n, m, board_commands):
                continue
            steps_length = 0
            r, c = i, j
            while is_valid(r, c, n, m):
                if board_marks[r][c] > 0:
                    # loop
                    steps_length += counter[board_marks[r][c]]
                    break
                r, c = execute_command(r, c, n, m, board_commands)
                steps_length += 1
            if steps_length > max_length:
                max_length = steps_length
                max_start_r, max_start_c = i, j

    return max_start_r+1, max_start_c+1, max_length


t = int(input())

for i in range(t):
    input()
    n, m = list(map(int, input().split(" ")))
    board_commands = []
    for j in range(n):
        board_commands.append(list(input()))

    r, c, d = solve(n, m, board_commands)
    print(r, c, d)
