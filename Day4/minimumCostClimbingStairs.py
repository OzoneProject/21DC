class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        l=[0 for i in range (len(cost)+1)]
        for i in range(2,len(cost)+1) :
            l[i]=min(l[i-2]+cost[i-2],l[i-1]+cost[i-1])
        return l[-1]
