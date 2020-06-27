from collections import Counter
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        c=Counter(words)
        c=c.most_common()
        ans=[]
        count=0
        i=0
        while(count<k) :
            n=c[i][1]
            l=[]
            for j in c[i:] :
                if j[1]==n :
                    l.append(j[0])
                else :
                    break
            l.sort()
            if count+len(l)<=k :
                ans.extend(l)
                count+=len(l)
                i+=len(l)
            else :
                ans.extend(l[:k-count])
                break
        return ans