class Solution(object):
    def minimumObstacles(self, grid):
        rows, cols = len(grid), len(grid[0])
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        
        pq = [(0, 0, 0)]
        visited = [[False] * cols for _ in range(rows)]
        
        while pq:
            obstacles, x, y = heappop(pq)
            
            if x == rows - 1 and y == cols - 1:
                return obstacles
            
            if visited[x][y]:
                continue
            visited[x][y] = True
            
            for dx, dy in directions:
                nx, ny = x+dx, y+dy
                
                if 0 <= nx < rows and 0 <= ny < cols and not visited[nx][ny]:
                    heappush(pq, (obstacles + grid[nx][ny], nx, ny))
        
        return -1 
        
