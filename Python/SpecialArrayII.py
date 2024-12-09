class Solution(object):
    def isArraySpecial(self, nums, queries):
        n = len(nums)
        ret = []

        if n < 2:
            return [True]*len(queries)

        prefix = [0]*n
        for i in range(1, n):
            prefix[i] = prefix[i-1]
            if nums[i] % 2 == nums[i-1] % 2:
                prefix[i] += 1

        for l, r in queries:
            if l == r:
                ret.append(True)
            else:
                if prefix[r] - prefix[l] == 0:
                    ret.append(True)
                else:
                    ret.append(False)

        return ret

    ''' Time limit exceeded lmao
    def isArraySpecial(self, nums, queries):
        ret = []

        if len(nums)<3:
            ret.append(nums[0]%2 != nums[1]%2)
            return ret

        for query in queries:
            valid = True
            for i in range(query[0]+1, query[1]):
                if nums[i]%2 == nums[i+1]%2 or nums[i]%2 == nums[i-1]%2:
                    ret.append(False)
                    valid = False
                    break
            
            if valid:
                ret.append(True)

        return ret
    '''
        
