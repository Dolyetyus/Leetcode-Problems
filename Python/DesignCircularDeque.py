class MyCircularDeque(object):
    def __init__(self, k):
        self.max = k
        self.deque = []
        self.size = 0
        
    def insertFront(self, value):
        if self.max == self.size:
            return False

        self.deque.insert(0, value)
        self.size += 1
        return True

    def insertLast(self, value):
        if self.max == self.size:
            return False

        self.deque.append(value)
        self.size += 1
        return True
        

    def deleteFront(self):
        if 0 == self.size:
            return False

        self.deque.pop(0)
        self.size -= 1
        return True

    def deleteLast(self):
        if 0 == self.size:
            return False

        self.deque.pop()
        self.size -= 1
        return True
        
    def getFront(self):
        if 0 == self.size:
            return -1

        return self.deque[0]

    def getRear(self):
        if 0 == self.size:
            return -1

        return self.deque[self.size-1]

    def isEmpty(self):
        if 0 == self.size:
            return True
        return False
        

    def isFull(self):
        if self.max == self.size:
            return True
        return False
        


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
