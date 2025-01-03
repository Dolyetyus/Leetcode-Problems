class Solution(object):
    def waysToSplitArray(self, nums):
        n = len(nums)
        prefix = []
        suffix = [0]*n

        total = 0
        reverse_total = 0
        for i in range(n):
            total+=nums[i]
            prefix.append(total)

            reverse_total+=nums[n-1-i]
            suffix[n-1-i] = reverse_total

        total = 0
        for i in range(n-1):
            if prefix[i]>=suffix[i+1]:
                total+=1

        return total
