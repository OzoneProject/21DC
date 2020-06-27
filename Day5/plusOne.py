class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        flag=0
        for i in digits :
            if i!=9 :
                flag=1
                break
        if flag==0 :
            l=[1]
            for i in range(len(digits)) :
                l.append(0)
            return l 
        else :
            c=1
            for i in range(len(digits)-1,-1,-1) :
                a=digits[i]+c
                if a>9 :
                    digits[i]=0
                    c=1
                else :
                    digits[i]=a
                    break
            return digits
