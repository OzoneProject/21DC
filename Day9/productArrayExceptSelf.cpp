class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1); // Array/vector with same size as that of nums and
                                         // initialised with 1.
        int left = 1, right = 1; // Variables to store the left and right product of nums 
                                 // array, respectively.
        
        for(int i = 0, j = nums.size() - 1; i < nums.size() - 1; i++, j--){
                                // Loop to iterate from 0 to n-1 index
            
            left *= nums[i];  // Storing product of elements at and to left of i 
            
            right *= nums[j]; // Storing product of elements at and to right of j 
            
            res[i+1] *= left; // Storing product of elements present to the left of i+1
            
            res[j-1] *= right; // Storing product of elements present to the right of j-1
        }
        
        return res; //return the vector/array.
    }
};