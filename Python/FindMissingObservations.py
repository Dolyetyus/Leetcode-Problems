class Solution(object):
    ''' Alternative slower solution
    def missingRolls(self, rolls, mean, n):
        ret = []
        total = (len(rolls) + n) * mean - sum(rolls)
        
        if total < n or total > 6 * n:
            return []
        
        for _ in range(0, n):
            ret.append(1)
            total -= 1

        while total > 0:
            for i in range(0, n):
                if total == 0:
                    break

                ret[i] += 1
                total -= 1

        return ret
    '''

    def missingRolls(self, rolls, mean, n):
        ret = []
        total = (len(rolls) + n) * mean - sum(rolls)
        
        if total < n or total > 6 * n:
            return []
        
        base = total // n
        remainder = total % n
        
        for i in range(n):
            if i < remainder:
                ret.append(base+1)
            else:
                ret.append(base)

        return ret
