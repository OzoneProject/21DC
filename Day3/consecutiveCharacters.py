class Solution:
    def maxPower(self, s: str) -> int:
        if len(s)==0 :
            return 0
        else :
            a=1
            u=1
            for i in range(1,len(s)) :
                if s[i]==s[i-1] :
                    u+=1
                else :
                    if u>a :
                        a=u
                    u=1
            if u>a :
                a=u
            return a
