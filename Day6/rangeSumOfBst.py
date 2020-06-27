# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        s=0
        if root.val<=R and root.val>=L :
            s+=root.val
        if root.left!= None and root.val>=L :
            s+=Solution.rangeSumBST(self,root.left,L,R)
        if root.right!=None and root.val<=R:
            s+=Solution.rangeSumBST(self,root.right,L,R)
        return s