class Solution(object):
    def minimumTotalDistance(self, robot, factory):
        robot.sort()
        factory.sort()
        dp = [0] + [float('inf')] * len(robot)
        for j, (factory_position, limit) in enumerate(factory):
            for _ in range(limit):
                for i in range(len(robot), 0, -1):
                    dp[i] = min(dp[i], dp[i-1] + abs(robot[i-1] - factory_position))
        return dp[-1]
