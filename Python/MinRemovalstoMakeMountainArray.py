class Solution(object):
    def minimumMountainRemovals(self, nums):
        n = len(nums)
        lis = [1] * n
        lds = [1] * n

        for i in range(1, n):
            for j in range(0, i):
                if nums[i] > nums[j]:
                    lis[i] = max(lis[i], lis[j] + 1)

        for i in range(n-2, -1, -1):
            for j in range(n-1, i, -1):
                if nums[i] > nums[j]:
                    lds[i] = max(lds[i], lds[j] + 1)

        maxMountainLen = 0
        for i in range(1, n-1):
            if lis[i] > 1 and lds[i] > 1:
                maxMountainLen = max(maxMountainLen, lis[i] + lds[i] - 1)

        return n - maxMountainLen

'''
lis = []
        lds = []

        for i in range(1, len(nums)):
            elements = 0
            index = i
            while nums[index-1]<nums[index]:
                elements+=1
                index+=1
            lis.append(elements)
        lis.append(0)

        for i in range(0, len(nums)-1):
            elements = 0
            index = i
            while index+1<len(nums) and nums[index]>nums[index+1]:
                elements += 1
                index += 1
            lds.append(elements)
        lds.append(0)
'''        
