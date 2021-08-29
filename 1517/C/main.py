from collections import deque

DEBUG = False 

def solve(n, p, board):
    def find_left(n, board, seed_points):
        point = seed_points[0]
        if (point[1] > 0) and (board[point[0]][point[1]-1] == 0):
            return (point[0], point[1]-1)

    def find_down(n, board, seed_points):
        point = seed_points[0]
        if (point[0] < n-1) and (board[point[0]+1][point[1]] == 0):
            return (point[0]+1, point[1])

    def find_next(n, board, seed_points):
        next_point = find_left(n, board, seed_points)
        if next_point is not None: 
            return next_point
        next_point = find_down(n, board, seed_points)
        if next_point is not None: 
            return next_point

        seed_points.popleft()
        return find_next(n, board, seed_points)

    for i in range(n):
        pi = p[i]
        seed_points = deque([(i, i)])
        for j in range(pi-1):
            next_point = find_next(n, board, seed_points)
            if DEBUG:
                print("j: " + str(j))
                print(next_point)
            if next_point is None: raise Exception()
            board[next_point[0]][next_point[1]] = pi 
            seed_points.appendleft(next_point)

            if DEBUG:
                for r in board:
                    print(" ".join(list(map(str, r))))
                print("")
    return board

def main():
    n = int(input())
    p = list(map(int, input().split()))
    board = []
    for i in range(n):
        row = [0] * i
        row.append(p[i])
        board.append(row)
    
    result = solve(n, p, board)

    for r in board:
        print(" ".join(list(map(str, r))))

main()