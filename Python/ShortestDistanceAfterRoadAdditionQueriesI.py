class Solution(object):
    def shortestDistanceAfterQueries(self, n, queries):
        graph = defaultdict(list)
        for i in range(n-1):
            graph[i].append(i+1)

        def bfs():
            queue = deque([(0, 0)])
            visited = set()
            
            while queue:
                current, distance = queue.popleft()
                
                if current == n-1: 
                    return distance
                
                if current in visited:
                    continue
                visited.add(current)
                
                for neighbor in graph[current]:
                    if neighbor not in visited:
                        queue.append((neighbor, distance+1))

        result = []
        for u, v in queries:
            graph[u].append(v)
            result.append(bfs())
            
        return result
        
