class Solution(object):
    def minimumOperations(self, nums):
        ret = 0
        for num in nums:
            if num%3!=0:
                ret+=1

        return ret
