class MinStack(object):
    def __init__(self):
        self.stack = []
        self.minStack = []

    def push(self, val):
        self.stack.append(val)
        if not self.minStack:
            self.minStack.append(val)
        elif val <= self.minStack[-1]:
            self.minStack.append(val)

    def pop(self):
        ret = self.stack.pop()
        if ret==self.minStack[-1]:
            self.minStack.pop()
        return ret

    def top(self):
        return self.stack[-1]

    def getMin(self):
        return self.minStack[-1]
