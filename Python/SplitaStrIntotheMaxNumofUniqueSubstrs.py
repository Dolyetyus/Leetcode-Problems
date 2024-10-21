class Solution(object):
    ''' Fails some edge cases
    def maxUniqueSplit(self, s):
        substr = set()
        i = 0

        while i < len(s):
            index = i
            string = s[i]
            
            while string in substr:
                index += 1
                if index == len(s):
                    return len(substr)
                string += s[index]
            
            substr.add(string)
            i += 1

        return len(substr)
    '''
    def maxUniqueSplit(self, s):
        substr = set()
        def backtrack(start):
            if start == len(s):
                return len(substr)
            
            max_splits = 0
            for end in range(start + 1, len(s) + 1):
                current_substring = s[start:end]
                if current_substring not in substr:
                    substr.add(current_substring)
                    max_splits = max(max_splits, backtrack(end))
                    substr.remove(current_substring)
            
            return max_splits
        
        return backtrack(0)
