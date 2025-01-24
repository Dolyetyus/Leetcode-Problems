class Solution(object):
    def eventualSafeNodes(self, graph):
        n = len(graph)
        reverse_graph = defaultdict(list)
        in_degree = [0] * n

        for node, neighbors in enumerate(graph):
            for neighbor in neighbors:
                reverse_graph[neighbor].append(node)
            in_degree[node] = len(neighbors)

        queue = deque([i for i in range(n) if in_degree[i] == 0])

        safe = [False] * n

        while queue:
            node = queue.popleft()
            safe[node] = True

            for neighbor in reverse_graph[node]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)

        return [i for i in range(n) if safe[i]]
