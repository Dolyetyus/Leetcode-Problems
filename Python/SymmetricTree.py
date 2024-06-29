class Solution:
    def isSameTree(self, p, q):
        if p==None and q == None:
            return True
        elif p == None or q == None:
            return False
        elif p.val != q.val:
            return False
        
        return self.isSameTree(p.left, q.right) and self.isSameTree(p.right, q.left)

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        return self.isSameTree(root.left, root.right)
