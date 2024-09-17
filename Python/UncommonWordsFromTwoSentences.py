class Solution(object):
    def uncommonFromSentences(self, s1, s2):
        dic = {}
        ret = []
        s1 = s1.split()
        s2 = s2.split()

        for word in s1:
            if word not in dic:
                dic[word] = 1
            else:
                dic[word] += 1
            
        for word in s2:
            if word not in dic:
                dic[word] = 1
            else:
                dic[word] += 1

        ret = {key : val for key, val in dic.items()
                   if val == 1}
        
        return ret
