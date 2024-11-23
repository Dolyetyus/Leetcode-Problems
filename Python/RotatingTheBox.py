class Solution(object):
    def rotateTheBox(self, box):
        for line in box:
            bottom = len(line)-1
            i = len(line)-1
            stones = 0
            while i>=0:
                if line[i] == '#':
                    stones += 1
                elif line[i] == '*':
                    pos = 0
                    while (stones>0):
                        line[bottom-pos] = '#'
                        pos += 1
                        stones-=1
                    while bottom-pos>i:
                        line[bottom-pos] = '.'
                        pos += 1
                    bottom = i-1

                i-=1

            if i<0:
                pos = 0
                while (stones>0):
                    line[bottom-pos] = '#'
                    pos += 1
                    stones-=1
                while bottom-pos>i:
                    line[bottom-pos] = '.'
                    pos += 1
        
        return list(zip(*box[::-1]))
