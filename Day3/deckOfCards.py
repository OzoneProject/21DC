class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        d={}
        for i in deck :
            d[i]=d.get(i,0)+1
        l=list(d.values())
       # print(l)
        gc=l[0]
        for i in range(1,len(l)) :
            a,b=max(gc,l[i]),min(gc,l[i])
            while b!=0 :
                a,b=b,a%b
            gc=a
        if gc>=2 :
            return True
        else :
            return False
