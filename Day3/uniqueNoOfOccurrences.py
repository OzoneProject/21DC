class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        d={}
        for i in arr :
            d[i]=d.get(i,0)+1
        l=list(d.values())
        if len(l)==1 :
            return True
        else :
            l.sort()
            for i in range(1,len(l)) :
                if l[i]==l[i-1] :
                    return False
            return True
