class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int dp[n];                   //Dynamic Programming Array
        
        dp[0] = cost[0], dp[1] = cost[1]; //First and second state are going to be unaffected
                                          // as they have no previous states
        
        for(int i = 2; i < n; i++){                 //Loop for updating the current state 
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]); // using the previous two states
        }
       
        return min(dp[n - 1], dp[n - 2]);  //Return min of last two states
    }
};