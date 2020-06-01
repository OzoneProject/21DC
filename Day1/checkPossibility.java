class Solution {
    public boolean checkPossibility(int[] nums) {
    int count=0;
        for(int i=0;i<nums.length-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                if(i>0)
                {
                    if(nums[i+1]<nums[i-1])
                    {
                        nums[i+1]=nums[i];
                    }
                    else nums[i]=nums[i-1];
                }
                count++;
            }

        }
        return count<=1;
    }
}