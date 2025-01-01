class Solution(object):
    def maxScore(self, s):
        prefix0 = []
        prefix1 = [0]*len(s)

        score = 0
        for num in s:
            if num == "0":
                score+=1
            prefix0.append(score)
        
        prefix0[-1] = prefix0[len(s)-2]

        score = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == "1":
                score+=1
            prefix1[i] = score

        prefix1[0] = prefix1[1]

        ret = 0
        for zero, one in zip(prefix0, prefix1):
            ret = max(zero+one, ret)

        return ret
