class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        s=[]
        for i in S :
            if i=='#' :
                if len(s)>=1 :
                    s.pop()
            else :
                s.append(i)
        t=[]
        for i in T :
            if i=='#' :
                if len(t)>=1 :
                    t.pop()
            else :
                t.append(i)
        return s==t
