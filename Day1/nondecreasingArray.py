class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        flag=1 
        c=0
        if len(nums)==1 :
            return True
        for i in range(1,len(nums)) :
            if nums[i]<nums[i-1] :
                t=nums[i]
                nums[i]=nums[i-1]
                for j in range(1,len(nums)) :
                    if nums[j]<nums[j-1] :
                        flag=0
                        break
                if flag==0:
                    nums[i]=t
                    if i!=len(nums) :
                        if i!=1 :
                            nums[i-1]=nums[i-2]
                        else :
                            nums[i-1]=-100000
                        for j in range(1,len(nums)) :
                            if nums[j]<nums[j-1] :
                                flag=-2
                                break
                break
        #print(nums)
        if flag==-2 :
            return False
        else :
            return True
