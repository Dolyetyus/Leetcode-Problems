class Solution(object):
    def makeFancyString(self, s):
        result = []
        i = 0

        while i < len(s):
            count = 1
            while i+1 < len(s) and s[i]==s[i+1]:
                i += 1
                count += 1
            
            result.append(s[i])
            if count > 1:
                result.append(s[i])
            
            i += 1

        return ''.join(result)

        ''' This one results in TLE lol
        letter_count = 0
        last_letter = ''
        i = 0
        while i < len(s):
            if last_letter == s[i]:
                letter_count += 1
                i+=1
                if i==len(s) and letter_count>2:
                    s = s[:i-letter_count+2] + s[i:]
                    i = i-letter_count+2
            else:
                if letter_count>2:
                    s = s[:i-letter_count+2] + s[i:]
                    i = i-letter_count+2
                last_letter = s[i]
                letter_count = 1
                i+=1

        return s
        '''
        
