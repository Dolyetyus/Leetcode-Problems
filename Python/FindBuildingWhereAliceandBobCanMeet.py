class Solution(object):
    '''def leftmostBuildingQueries(self, heights, queries):
        ret = []

        for query in queries:
            alice = heights[query[0]]
            bob = heights[query[1]]
            moved = False
            start = max(query[0], query[1])

            for i in range(start, len(heights)):
                if i == start and query[0]>query[1]:
                    if (alice <= heights[i] and bob < heights[i]):
                        ret.append(i)
                        moved = True
                        break
                elif i == start and query[0]<query[1]:
                    if (alice < heights[i] and bob <= heights[i]):
                        ret.append(i)
                        moved = True
                        break
                elif i == start and query[0]==query[1]:
                    if (alice <= heights[i] and bob <= heights[i]):
                        ret.append(i)
                        moved = True
                        break
                else:
                    if (alice < heights[i] and bob < heights[i]):
                        ret.append(i)
                        moved = True
                        break

            if not moved:
                ret.append(-1)
        
        return ret'''
        
    def leftmostBuildingQueries(self, heights, queries):
        n, q = len(heights), len(queries)
        result = [-1] * q
        deferred = [[] for _ in range(n)]
        pq = []

        for i in range(q):
            a, b = queries[i]
            if a > b:
                a, b = b, a
            if a == b or heights[a] < heights[b]:
                result[i] = b
            else:
                deferred[b].append((heights[a], i))

        for i in range(n):
            for query in deferred[i]:
                heapq.heappush(pq, query)
            while pq and pq[0][0] < heights[i]:
                result[pq[0][1]] = i
                heapq.heappop(pq)

        return result
