class Solution(object):
    def findSum(self, root, depth, arr):
        if not root:
            return
        if len(arr)<depth+1:
            arr.append(0)
        
        self.findSum(root.left, depth+1, arr)
        arr[depth]+=root.val
        self.findSum(root.right, depth+1, arr)

    def traverseCousins(self, root, depth, arr, sum):
        if not root:
            return
        if depth < 2:
            root.val = 0

        siblingSum = 0
        if root.left:
            siblingSum += root.left.val
        if root.right:
            siblingSum += root.right.val

        self.traverseCousins(root.left, depth+1, arr, siblingSum)
        root.val = arr[depth] - sum
        self.traverseCousins(root.right, depth+1, arr, siblingSum)

    def replaceValueInTree(self, root):
        arr = []
        self.findSum(root, 0, arr)
        self.traverseCousins(root, 0, arr, 0)
        root.val = 0
        return root
        
