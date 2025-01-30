class Solution(object):
    def magnificentSets(self, n, edges):
        graph = [[] for _ in range(n+1)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        visited = [False] * (n + 1)
        total_groups = 0
        
        for node in range(1, n + 1):
            if not visited[node]:
                is_bipartite = True
                color = {}
                q = deque()
                component = []
                q.append(node)
                color[node] = 0
                visited[node] = True
                component.append(node)
                
                while q:
                    u = q.popleft()
                    for v in graph[u]:
                        if v not in color:
                            color[v] = color[u] ^ 1
                            visited[v] = True
                            component.append(v)
                            q.append(v)
                        else:
                            if color[v] == color[u]:
                                is_bipartite = False
                
                if not is_bipartite:
                    return -1
                
                max_depth = 0
                for start in component:
                    depth = {}
                    q = deque()
                    q.append(start)
                    depth[start] = 1
                    current_max = 1
                    
                    while q:
                        u = q.popleft()
                        for v in graph[u]:
                            if v not in depth:
                                depth[v] = depth[u] + 1
                                current_max = max(current_max, depth[v])
                                q.append(v)
                    
                    max_depth = max(max_depth, current_max)
                
                total_groups += max_depth
        
        return total_groups
