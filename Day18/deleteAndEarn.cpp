int deleteAndEarn(vector<int>& nums) {
    
        if (nums.size() == 0) return 0;
    int maxx = 0;
    for (int num : nums) maxx = max(num, maxx);
    if (maxx == 1) return nums.size();
    int dp[maxx+1];
    for(int i=0;i<maxx+1;i++)dp[i]=0;
    for (int num : nums) dp[num] += num;
    dp[maxx+1-2] = max(dp[maxx+1-2], dp[maxx+1-1]);
    for (int i = maxx+1-3; i >= 0; i--) {
        dp[i] = max(dp[i+1], dp[i] + dp[i+2]);
    }
    
    return dp[0];

}