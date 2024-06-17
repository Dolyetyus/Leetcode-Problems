class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        seen = set()
        write_index = 0
        
        for num in nums:
            if num not in seen:
                seen.add(num)
                nums[write_index] = num
                write_index += 1
                
        return write_index
