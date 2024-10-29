class Solution(object):
    def __init__(self):
        self.ret = 0

    ''' Results in Time Limit Exceeded
    def move(self, grid, currentPos, moves):
        validMoves = [[-1, +1], [0, +1], [+1, +1]]
        for move in validMoves:
            tempY = currentPos[0] + move[0]
            tempX = currentPos[1] + move[1]
            if tempY < 0 or tempY >= len(grid) or tempX >= len(grid[0]):
                continue
            if grid[tempY][tempX] > grid[currentPos[0]][currentPos[1]]:
                self.move(grid, [tempY, tempX], moves + 1)
        self.ret = max(self.ret, moves)

    def maxMoves(self, grid):
        self.ret = 0  
        for i in range(len(grid)):
            self.move(grid, [i, 0], 0)
        return self.ret
    '''

    def maxMoves(self, grid):
        m, n = len(grid), len(grid[0])
        dp = [[0] * n for _ in range(m)]
        max_moves = 0

        for col in range(n - 2, -1, -1):
            for row in range(m):
                if row > 0 and grid[row][col] < grid[row - 1][col + 1]:
                    dp[row][col] = max(dp[row][col], dp[row - 1][col + 1] + 1)
                if grid[row][col] < grid[row][col + 1]:
                    dp[row][col] = max(dp[row][col], dp[row][col + 1] + 1)
                if row < m - 1 and grid[row][col] < grid[row + 1][col + 1]:
                    dp[row][col] = max(dp[row][col], dp[row + 1][col + 1] + 1)

        for row in range(m):
            max_moves = max(max_moves, dp[row][0])
        return max_moves
