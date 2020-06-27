class Solution:
    def isValid(self, s: str) -> bool:
        l=[]
        for i in s :
            if i=='(' :
                l.append('(')
            elif i=='{' :
                l.append('{')
            elif i=='[' :
                l.append('[')
            else :
                if len(l)>0 :
                    x=l.pop()
                    if (i==')' and x!='(') or (i==']' and x!='[') or (i=='}' and x!='{') :
                        return False
                else :
                    return False
        if len(l)==0 :
            return True
        else :
            return False