# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # base case
        if root == None or root == p or root ==q:
            return root

        # recursion
        leftt = self.lowestCommonAncestor(root.left, p, q)
        rightt = self.lowestCommonAncestor(root.right, p,q)

        # result
        if leftt == None:
            return rightt
        elif rightt == None:
            return leftt
        
        return root
        