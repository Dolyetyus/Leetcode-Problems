class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [1] * size

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1

class Solution:
    def lexicographicallySmallestArray(self, nums, limit):
        n = len(nums)
        uf = UnionFind(n)

        indexed_nums = sorted((val, idx) for idx, val in enumerate(nums))

        for i in range(n - 1):
            if abs(indexed_nums[i][0] - indexed_nums[i + 1][0]) <= limit:
                uf.union(indexed_nums[i][1], indexed_nums[i + 1][1])

        groups = {}
        for i in range(n):
            root = uf.find(i)
            if root not in groups:
                groups[root] = []
            groups[root].append(i)

        result = nums[:]
        for indices in groups.values():
            sorted_indices = sorted(indices)
            sorted_values = sorted(result[i] for i in indices)
            for idx, val in zip(sorted_indices, sorted_values):
                result[idx] = val

        return result
        
