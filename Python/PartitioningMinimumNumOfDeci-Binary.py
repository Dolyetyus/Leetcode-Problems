class Solution(object):
    def minPartitions(self, n):
        ret = '0'
        for num in n:
            ret = max(ret, num)

        return int(ret)
