class Solution(object):
    def findRedundantConnection(self, edges):
        parent = [i for i in range(len(edges) + 1)]
        
        def find(u):
            if parent[u] != u:
                parent[u] = find(parent[u])
            return parent[u]
        
        def union(u, v):
            root_u = find(u)
            root_v = find(v)
            if root_u == root_v:
                return False
            parent[root_v] = root_u
            return True
        
        for u, v in edges:
            if not union(u, v):
                return [u, v]
        
        return []
        
