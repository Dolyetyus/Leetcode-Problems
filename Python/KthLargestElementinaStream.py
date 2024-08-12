class KthLargest(object):
    def __init__(self, k, nums):
        self.k = k
        nums.sort()
        nums = nums[-k:]
        self.nums = nums

    def add(self, val):
        if len(self.nums) < self.k:
            self.nums.append(val)
        elif val > self.nums[0]:
            self.nums[0] = val
        else:
            return self.nums[0]

        self.nums.sort()
        return self.nums[0]
