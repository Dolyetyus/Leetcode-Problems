class Solution(object):
    def minCost(self, grid):
        m, n = len(grid), len(grid[0])
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        pq = [(0, 0, 0)]
        visited = [[False] * n for _ in range(m)]

        while pq:
            cost, x, y = heappop(pq)

            if visited[x][y]:
                continue
            visited[x][y] = True

            if (x, y) == (m - 1, n - 1):
                return cost

            for i, (dx, dy) in enumerate(directions):
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n:
                    new_cost = cost + (1 if i + 1 != grid[x][y] else 0)
                    heappush(pq, (new_cost, nx, ny))
        
