class Solution {
    public int maxSumDivThree(int[] nums) {
        int sum = 0;
        int one= 10001;
        int two = 10001;
        
        for(int num : nums)
        {
            sum += num;
            
            if(num % 3 == 1)
            {
                two = Math.min(two, one + num);
                one = Math.min(one, num); 
            }
            
            if(num % 3 == 2)
            {
                one = Math.min(one, two + num);
                two= Math.min(two, num);
                 
            }
        }
        
        if(sum % 3 == 0)
            return sum;
        
        if(sum % 3 == 1)
            return sum - one;
        
        if(sum % 3 == 2)
            return sum - two;
        
        return 0;
            
    }
}





