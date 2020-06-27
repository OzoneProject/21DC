class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        l=len(target)
        i=1
        j=0
        o=[]
        while (True) :
            if target[j]==i :
                o.append("Push")
                i+=1 
                j+=1
            else :
                o.append("Push")
                o.append("Pop")
                i+=1
            if j==l :
                break
        return o