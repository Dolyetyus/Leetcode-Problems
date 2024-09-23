class Solution(object):
    def minExtraChar(self, s, dictionary):
        word_set = set(dictionary)
        memo = {}

        def dp(i):
            if i == len(s):
                return 0
            if i in memo:
                return memo[i]
            
            min_extra = 2147483646
            for j in range(i + 1, len(s) + 1):
                current_substring = s[i:j]
                extra_chars = 0 if current_substring in word_set else len(current_substring)
                min_extra = min(min_extra, extra_chars + dp(j))
            
            memo[i] = min_extra
            return min_extra

        return dp(0)
