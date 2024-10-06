class Solution(object):
    def areSentencesSimilar(self, sentence1, sentence2):
        list1 = sentence1.split()
        list2 = sentence2.split()

        if len(list1) > len(list2):
            list1, list2 = list2, list1

        i = 0
        j = 0

        while i < len(list1) and list1[i] == list2[i]:
            i += 1

        while j < len(list1) and list1[-(j+1)] == list2[-(j+1)]:
            j += 1

        return i+j >= len(list1)
        
