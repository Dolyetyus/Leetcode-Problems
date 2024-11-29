class Solution(object):
    def minimumTime(self, grid):
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1

        rows, cols = len(grid), len(grid[0])
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        
        pq = [(0, 0, 0)]
        visited = [[False] * cols for _ in range(rows)]
        
        while pq:
            time, x, y = heappop(pq)
            
            if x == rows-1 and y == cols-1:
                return time
            
            if visited[x][y]:
                continue
            visited[x][y] = True
            
            for dx, dy in directions:
                nx, ny = x+dx, y+dy
                
                if 0 <= nx < rows and 0 <= ny < cols:
                    required_time = grid[nx][ny]
                    wait_time = (required_time-time+1)%2
                    next_time = max(time+1, required_time+wait_time)
                    
                    heappush(pq, (next_time, nx, ny))
        
        return -1 
        
