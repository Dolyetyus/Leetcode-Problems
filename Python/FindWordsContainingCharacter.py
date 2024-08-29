class Solution(object):
    def findWordsContaining(self, words, x):
        i = 0
        ret = []
        for word in words:
            if x in word:
                ret.append(i)
            i+=1
        
        return ret
