class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        c=0
        while (x>0 or y>0) :
            if x%2==y%2 :
                pass
            else :
                c+=1
            x=x//2
            y=y//2
        return c
