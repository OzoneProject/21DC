public:
    bool isMatch(string s, string p) {
        int psize = p.size();
        int ssize = s.size();
        string pp = "";
        vector<bool> star;
        for (int i=0; i<psize; ++i) {
            if (p[i] == '*')
                star.back() = true;
            else {
                star.push_back(false);
                pp += p[i];
            }
        }
        
        psize = pp.size();

        bool dp[psize+1][ssize+1];
        memset(dp, false, sizeof(dp));
        
        dp[0][0] = true;
        
        for (int i=1; i<=psize; i++) {
            if (star[i-1] == true)
                dp[i][0] = true;
            else
                break;
        }
        
        for (int i=1; i<=psize; i++) {
            for (int j=1; j<=ssize; j++) {
                // case 1:
                if (dp[i-1][j-1] == true) {
                    if (pp[i-1] == s[j-1] || pp[i-1] == '.') {
                        dp[i][j] = true;
                        continue;
                    }
                }
                
                // case 2:
                if (dp[i-1][j] == true) {
                    if (star[i-1] == true) {
                        dp[i][j] = true;
                        continue;
                    }
                }
                // case 3:
                if (dp[i][j-1] == true) {
                    if (star[i-1] == true && (pp[i-1] == s[j-1] || pp[i-1] == '.')) {
                        dp[i][j] = true;
                        continue;
                    }
                }
            }
        }
        
        return dp[psize][ssize];
    }
};