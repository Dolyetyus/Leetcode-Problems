class Solution(object):
    def isPalindrome(self, s):
        if len(s)<2:
            return True
            
        left = 0
        right = len(s)-1
        while (left<right):
            while(left < right and not s[left].isalnum()):
                left+=1
            while(left < right and not s[right].isalnum()):
                right-=1

            if (s[left].lower() != s[right].lower()):
                return False
        
            right-=1
            left+=1

        return True
