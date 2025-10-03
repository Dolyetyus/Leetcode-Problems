class Solution(object):
    def trapRainWater(self, heightMap):
        m, n = len(heightMap), len(heightMap[0])
        visited = [[False] * n for _ in range(m)]
        heap = []
        
        for i in range(m):
            for j in range(n):
                if i == 0 or i == m-1 or j == 0 or j == n-1:
                    heappush(heap, (heightMap[i][j], i, j))
                    visited[i][j] = True

        water_trapped = 0
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while heap:
            height, x, y = heappop(heap)
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny]:
                    water_trapped += max(0, height - heightMap[nx][ny])
                    heappush(heap, (max(height, heightMap[nx][ny]), nx, ny))
                    visited[nx][ny] = True

        return water_trapped
        
