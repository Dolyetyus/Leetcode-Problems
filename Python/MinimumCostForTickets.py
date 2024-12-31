class Solution(object):
    def mincostTickets(self, days, costs):
        days_set = set(days)
        last_day = days[-1]
        dp = [0] * (last_day + 1)

        for i in range(1, last_day + 1):
            if i not in days_set:
                dp[i] = dp[i-1]
            else:
                dp[i] = min(
                    dp[i-1] + costs[0],
                    dp[i-7] + costs[1] if i >= 7 else costs[1],
                    dp[i-30] + costs[2] if i >= 30 else costs[2],
                )

        return dp[last_day]
            
