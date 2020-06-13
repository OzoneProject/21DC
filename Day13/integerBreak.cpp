class Solution {
public:
    int integerBreak(int n) {
        
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        
        int prod = 1;
        
        while(n > 4){   // So that we get factors equal to 2 and 3 only. The min value n > 4 
            prod *= 3;  // will satisfy is n = 5, which will have factors 2 * 3.
            n -= 3;     // Rest will follow.
        }
        
        prod *= n;
        
        return prod;
    }
};