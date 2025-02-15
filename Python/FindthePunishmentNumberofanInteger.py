class Solution(object):
    def punishmentNumber(self, n):
        arr = [1,9,10,36,45,55,82,91,99,100,235,297,369,370,379,414,657,675,703,756,792,909,918,945,964,990,991,999,1000]
        ans = [1,9,10,36,45,55,82,91,99,100,235,297,369,370,379,414,657,675,703,756,792,909,918,945,964,990,991,999,1000]

        for i in range(1, len(ans)):
            ans[i] *= ans[i]

        for i in range(1, len(ans)):
            ans[i] += ans[i-1]

        for i in range(len(arr)):
            if arr[i]>n:
                return ans[i-1]

        return ans[-1]
        
