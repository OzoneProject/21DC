class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
         int sum = 0;
        int one= 10001;
        int two = 10001;
        
        for(int num : nums)
        {
            sum += num;
            
            if(num % 3 == 1)
            {
                two = min(two, one + num);
                one = min(one, num); 
            }
            
            if(num % 3 == 2)
            {
                one = min(one, two + num);
                two= min(two, num);
                 
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
};

