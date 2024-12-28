class Solution(object):
    def findTargetSumWays(self, nums, target):
        dp = defaultdict(int)
        dp[0] = 1

        for num in nums:
            next_dp = defaultdict(int)
            for current_sum, count in dp.items():
                next_dp[current_sum + num] += count
                next_dp[current_sum - num] += count
            dp = next_dp

        return dp[target]
