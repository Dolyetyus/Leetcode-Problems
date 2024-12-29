class Solution(object):
    def numWays(self, words, target):
        m, n = len(words[0]), len(target)

        char_count = [[0] * 26 for _ in range(m)]
        for word in words:
            for i, char in enumerate(word):
                char_count[i][ord(char)-ord('a')] += 1

        dp = [0] * (n+1)
        dp[0] = 1

        for i in range(m):
            for j in range(n, 0, -1):
                char_index = ord(target[j-1]) - ord('a')
                dp[j] += dp[j-1] * char_count[i][char_index]
                dp[j] %= (10**9+7)

        return dp[n]
        
