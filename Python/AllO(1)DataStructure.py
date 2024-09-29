class AllOne(object):
    def __init__(self):
        self.hmap = {}

    def inc(self, key):
        if key in self.hmap:
            self.hmap[key] += 1
        else:
            self.hmap[key] = 1

    def dec(self, key):
        if self.hmap[key]-1 == 0:
            self.hmap.pop(key)
        else:
            self.hmap[key] -= 1

    def getMaxKey(self):
        if not self.hmap:
            return ""
        maxVal = max(self.hmap.values())
        for key in self.hmap.keys():
            if self.hmap[key] == maxVal:
                return key
        
    def getMinKey(self):
        if not self.hmap:
            return ""
        minVal = min(self.hmap.values())
        for key in self.hmap.keys():
            if self.hmap[key] == minVal:
                return key
