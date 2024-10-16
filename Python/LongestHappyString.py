class Solution(object):
    def longestDiverseString(self, a, b, c):
        counta = 0
        countb = 0
        countc = 0
        total = a+b+c
        ret = ""
        
        for i in range(total):
            if a>0 and counta<2 and (a>=b or countb==2) and (a>=c or countc==2):
                ret += "a"
                counta += 1
                countb = 0
                countc = 0
                a-=1
            elif b>0 and countb<2 and (b>=a or counta==2) and (b>=c or countc==2):
                ret += "b"
                countb += 1
                counta = 0
                countc = 0
                b-=1
            elif c>0 and countc<2 and (c>=a or counta==2) and (c>=b or countb==2):
                ret += "c"
                countc += 1
                counta = 0
                countb = 0
                c-=1

        return ret
