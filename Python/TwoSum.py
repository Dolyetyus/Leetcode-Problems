class Solution(object):
    def twoSum(self, nums, target):
        hashmap = {}
        for i in range(len(nums)):
            hashmap[nums[i]] = i

        for i in range(len(nums)):
            seek = target - nums[i]
            if seek in hashmap and hashmap[seek] != i:
                return [i, hashmap[seek]]

        return []
