class Solution(object):
    def isSameTree(self, p, q):
        if p==None and q == None:
            return True
        elif p == None or q == None:
            return False
        elif p.val != q.val:
            return False
        
        return self.isSameTree(p.right, q.right) and self.isSameTree(p.left, q.left)
        
