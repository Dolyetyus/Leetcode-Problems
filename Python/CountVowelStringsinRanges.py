class Solution(object):
    def vowelStrings(self, words, queries):
        vowels = set('aeiou')
        prefix = [0]
        num = 0
        for word in words:
            if word[0] in vowels and word[-1] in vowels:
                num+=1
            prefix.append(num)

        ret = []
        for query in queries:
            ret.append(prefix[query[1]+1]-prefix[query[0]])

        return ret
