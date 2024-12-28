class Solution(object):
    def maxSumOfThreeSubarrays(self, nums, k):
        n = len(nums)
        window_sums = [0] * (n - k + 1)
        
        current_sum = sum(nums[:k])
        window_sums[0] = current_sum
        for i in range(1, len(window_sums)):
            current_sum += nums[i + k - 1] - nums[i - 1]
            window_sums[i] = current_sum
        
        left = [0] * len(window_sums)
        right = [0] * len(window_sums)
        
        max_idx = 0
        for i in range(len(window_sums)):
            if window_sums[i] > window_sums[max_idx]:
                max_idx = i
            left[i] = max_idx
        
        max_idx = len(window_sums) - 1
        for i in range(len(window_sums) - 1, -1, -1):
            if window_sums[i] >= window_sums[max_idx]:
                max_idx = i
            right[i] = max_idx
        
        max_sum = 0
        result = []
        for mid in range(k, len(window_sums) - k):
            l = left[mid - k]
            r = right[mid + k]
            total = window_sums[l] + window_sums[mid] + window_sums[r]
            if total > max_sum:
                max_sum = total
                result = [l, mid, r]
        
        return result

        
