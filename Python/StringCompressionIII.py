class Solution(object):
    def compressedString(self, word):
        ret = []
        count = 0
        prev_letter = word[0]

        for letter in word:
            if prev_letter != letter:
                ret.append(str(count))
                ret.append(prev_letter)
                prev_letter = letter
                count = 1
            elif count==9:
                ret.append(str(count))
                ret.append(prev_letter)
                count = 1
            else:
                count += 1
        
        ret.append(str(count))
        ret.append(prev_letter)

        return "".join(ret)
