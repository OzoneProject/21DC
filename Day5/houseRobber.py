class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)==0 :
            return 0
        elif len(nums)==1 :
            return nums[0]
        elif len(nums)==2 :
            return max(nums)
        else :
            a=[nums[0],max(nums[1],nums[0])]
            for i in range(2,len(nums)) :
                a.append(max(a[i-1],a[i-2]+nums[i]))
            return a[-1]
                
