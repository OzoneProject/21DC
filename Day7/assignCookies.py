class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        j=0
        c=0
        for i in s:
            if j==len(g) :
                break
            if i<g[j] :
                continue
            else :
                c+=1
                j+=1
        return c