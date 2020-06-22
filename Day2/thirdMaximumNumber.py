class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        ma=max(nums)
        i=0
        while i<len(nums) :
            if nums[i]==ma :
                del nums[i]
            else :
                i+=1
        if len(nums)==0 :
            return ma
        else :
            sm=max(nums)
            i=0
            while i<len(nums) :
                if nums[i]==sm :
                    del nums[i]
                else :
                    i+=1
            if len(nums)==0 :
                return ma
            else :
                return max(nums)
