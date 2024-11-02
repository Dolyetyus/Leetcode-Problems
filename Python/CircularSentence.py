class Solution(object):
    def isCircularSentence(self, sentence):
        n = len(sentence)
        if n == 1:
            return True
        
        if sentence[0]!=sentence[-1]:
            return False

        for i in range(n):
            if sentence[i]==' ' and sentence[i-1]!=sentence[i+1]:
                return False

        return True
