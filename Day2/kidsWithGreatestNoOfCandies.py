class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        ma=max(candies)
        l=[]
        for i in candies :
            if i+extraCandies>=ma :
                l.append(True)
            else :
                l.append(False)
        return l
