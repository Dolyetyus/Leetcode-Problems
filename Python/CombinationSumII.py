class Solution(object):
    def combinationSum2(self, candidates, target):
        def backtrack(start, remaining, path, result):
            if remaining == 0:
                result.append(path[:])
                return
            elif remaining < 0:
                return
            
            for i in range(start, len(candidates)):
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                
                path.append(candidates[i])
                backtrack(i + 1, remaining - candidates[i], path, result)
                path.pop()

        candidates.sort()
        result = []
        backtrack(0, target, [], result)
        return result
