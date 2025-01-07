class Solution(object):
    def stringMatching(self, words):
        temp = []
        ret = set(temp)

        for i in range(len(words)):
            for ii in range(len(words)):
                if len(words[i])<len(words[ii]):
                    if words[i] in words[ii]:
                        ret.add(words[i])
        
        return list(ret)
        
