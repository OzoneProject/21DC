class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        a=0
        for i in range(len(prices)) :
            p=max(prices[i:])-prices[i]
            if p >a:
                a=p
        return a
