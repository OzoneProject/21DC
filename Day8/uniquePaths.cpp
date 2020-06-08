class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n]; //Defining Dynamic Prog. matrix of size m x n.
        
        for(int i = 1; i < m; i++){ 
            dp[i][0] = 1;       //Initialising the elements of first row equal to 1
        }
        
        for(int i = 1; i < n; i++){
            dp[0][i] = 1;       //Initialising the elements of first column equal to 1
        }
        
        for(int i = 1; i < m; i++){  //Traversing the entire matrix
            for(int j = 1; j < n; j++){
                                                    //The current state will be equal to the
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; // sum of adjacent states. As robot can 
                                                    // come from top and left only to the 
                                                    // current state, current state will be
            }                                       // equal to sum of left and top state.
        }
        
        return dp[m-1][n-1]; // Return the last state, that is the state of the Finish cell.
    }
};