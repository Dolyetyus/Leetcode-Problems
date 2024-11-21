class Solution:
    def countUnguarded(self, m, n, guards, walls):
        dp = [[0] * n for _ in range(m)]
        for x, y in guards+walls:
            dp[x][y] = 1
               
        directions = [(0, 1), (1, 0), (-1, 0), (0, -1)]
        
        for x, y in guards:
            for dx, dy in directions:
                curr_x = x
                curr_y = y
                
                while 0<=curr_x+dx<m and 0<=curr_y+dy<n and dp[curr_x+dx][curr_y+dy] != 1:
                    curr_x += dx
                    curr_y += dy
                    dp[curr_x][curr_y] = 2
                    
        return sum(1 for i in range(m) for j in range(n) if dp[i][j]==0)                    

    ''' Gives TLE lmao
    def knight(self, grid, y, x, ret):
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for dy, dx in directions:
            ny, nx = y, x
            while 0<=ny<len(grid) and 0<=nx<len(grid[0]) and grid[ny][nx] != 8:
                if grid[ny][nx] == 1 or grid[ny][nx] == 4:
                    ny += dy
                    nx += dx
                    continue
                else:
                    grid[ny][nx] = 1
                    ret -= 1
                    ny += dy
                    nx += dx

        return ret

    def countUnguarded(self, m, n, guards, walls):
        grid = [[0 for _ in range(n)] for _ in range(m)]
        ret = n*m

        for guard in guards:
            grid[guard[0]][guard[1]] = 4
            ret-=1
        
        for wall in walls:
            grid[wall[0]][wall[1]] = 8
            ret-=1

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 4:
                    ret = self.knight(grid, i, j, ret)

        return ret
        '''
