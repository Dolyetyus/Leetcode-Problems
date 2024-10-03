class Solution(object):
    def minSubarray(self, nums, p):
        total = sum(nums)
        modulo = total % p
        if modulo == 0:
            return 0
        
        prefix_sum = 0
        min_length = len(nums)
        n = min_length
        prefix_dict = {0: -1} 
        
        for i, num in enumerate(nums):
            prefix_sum += num
            current_mod = prefix_sum % p
            target_mod = (current_mod - modulo) % p
            
            if target_mod in prefix_dict:
                min_length = min(min_length, i - prefix_dict[target_mod])
            
            prefix_dict[current_mod] = i
        
        return min_length if min_length < n else -1
