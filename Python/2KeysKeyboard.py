class Solution(object):
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
        """
        steps = 0
        d = 2
        
        while n > 1:
            while n % d == 0:
                steps += d
                n //= d
            d += 1
        
        return steps
