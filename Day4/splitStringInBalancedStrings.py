class Solution:
    def balancedStringSplit(self, s: str) -> int:
        c=0
        v=0
        for i in s :
            if i=='L' :
                v+=1
            else :
                v-=1
            if v==0 :
                c+=1
        return c
