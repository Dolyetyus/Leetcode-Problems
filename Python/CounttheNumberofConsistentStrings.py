class Solution(object):
    def countConsistentStrings(self, allowed, words):
        ret = 0
        flag = True
        for word in words:
            for letter in word:
                if letter not in allowed:
                    flag = False
                    break
            if (flag):
                ret += 1
            flag = True

        return ret
        
