class Solution(object):
    def countPaths(self, n, roads):
        graph = {}
        for u, v, time in roads: 
            graph.setdefault(u, []).append((v, time))
            graph.setdefault(v, []).append((u, time))
        
        dist = [99999999999999999] * n
        dist[0] = 0
        ways = [0] * n
        ways[0] = 1
        
        pq = [(0, 0)]
        while pq: 
            d, u = heappop(pq)
            if d > dist[-1]: break
            if d == dist[u]: 
                for v, time in graph.get(u, []): 
                    if dist[u] + time < dist[v]: 
                        dist[v] = dist[u] + time
                        ways[v] = ways[u]
                        heappush(pq, (dist[v], v))
                    elif dist[u] + time == dist[v]: 
                        ways[v] += ways[u]

        return ways[-1]%1000000007
