class Solution(object):
    def dividePlayers(self, skill):
        n = len(skill)
        sort = sorted(skill)
        total = 0
        total = sort[0] + sort[-1]
        ret = 0
        
        for i in range(n/2):
            temp = sort[i] + sort[n-1-i]
            ret += sort[i] * sort[n-1-i]
            if temp!=total:
                return -1

        return ret
