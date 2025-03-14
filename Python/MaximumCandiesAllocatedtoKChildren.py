class Solution(object):
    def maximumCandies(self, candies, k):
        def isValidSize(group_candies):
            groups = 0
            for candy in candies:
                groups += candy // group_candies
            return groups >= k

        left, right = 0, sum(candies) // k

        while left < right:
            mid = 1 + (left + right) // 2
            
            if isValidSize(mid):
                left = mid
            else:
                right = mid-1 
        
        return left
        
