class Solution {
public:
    int gen(string& s, string& t, int i, int j, vector<vector<int>>& dp){ // Need to pass DP by
                                                                // reference or make it global.

        if(j == t.length()) // If j reaches to end of 't', it means that we have every letter
            return 1;       // of t somewhere in 's'. So, we return 1, i.e. 1 subsequence 
                            // is present in 's'.

        if(i == s.length()) // If i reaches to end of 's', and j is still not at end, tha means
            return 0;       // that j is not entirely present in this part of 's', therefore
                            // we return 0, i.e. we have 0 or no subsequence in 's'.

        if(dp[i][j] != -1)   // If this comb. of (i, j) is visited already, dp[i][j] will not
            return dp[i][j]; // be -1, it will be >= 0, therefore, we return dp[i][j].
                             // If it's still -1, we do nothing.

        int tot = 0;    // Stores all the possible subsequences present on and after the
                        // combination (i, j).

        for(int p = i; p < s.length(); p++){ // Iterate on the remaining 's', i.e. from p index

            if(s[p] == t[j])                        // If characters on i of 's' and j of 't'
                tot += gen(s, t, p + 1, j + 1, dp); // are equal, or same, then we move forward
                                                    // in recursion to check if there is a 
                                                    // subsequence present from i+1 onwards in
                                                    // 's' & j+1 onwards in 't', and get the 
                                                    // no. of present subsequences.
        }
                                // Return the current total, that is the no. of possible 
        return dp[i][j] = tot;  // subsequences present from (i, j) onwards in 's' & 't' resp.
    }                           // Simultaneously store it in dp for future use.

    int numDistinct(string s, string t) {

        vector<vector<int>> v(s.length(), vector<int> (t.length(), -1)); // The DP matrix.

        return gen(s, t, 0, 0, v); // Return the subsequences from (0, 0) onwards in 's' & 't'.
    }
};