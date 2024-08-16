class Solution(object):
    def maxDistance(self, arrays):
        minNum = arrays[0][0]
        maxNum = arrays[0][-1]
        res = 0

        for i in range(1, len(arrays)):
            current_min = arrays[i][0]
            current_max = arrays[i][-1]

            res = max(res, abs(current_max - minNum))
            res = max(res, abs(maxNum - current_min))

            minNum = min(minNum, current_min)
            maxNum = max(maxNum, current_max)

        return res
