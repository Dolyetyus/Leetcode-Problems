class Solution(object):
    def stringHash(self, s, k):
        ret = []
        i = 0
        while (i<len(s)-k+1):
            total = 0
            for x in range(k):
                total += ord(s[i+x])-97

            total %= 26
            total += 97
            ret.append(chr(total))
            i+=k

        return ''.join(ret)
