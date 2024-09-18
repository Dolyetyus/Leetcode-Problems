class Solution(object):
    def largestNumber(self, nums):
        num = [str(num) for num in nums]
        
        def compare(x, y):
            if x + y > y + x:
                return -1
            elif x + y < y + x:
                return 1
            else:
                return 0
        
        num.sort(key=cmp_to_key(compare))
                
        return '0' if num[0] == '0' else "".join(num)
