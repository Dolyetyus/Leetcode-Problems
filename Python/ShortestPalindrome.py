class Solution(object):
    def shortestPalindrome(self, s):
        if not s:
            return s

        reverse = s[::-1]
        for i in range(len(s)):
            if s.startswith(reverse[i:]):
                return reverse[:i] + s
                
        return ""
