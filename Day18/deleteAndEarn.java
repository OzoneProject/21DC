
class Solution {

	public int deleteAndEarn(int[] nums) {
        if (nums.length == 0) return 0;
        int max = 0;
        for (int num : nums) max = Math.max(num, max);
        if (max == 1) return nums.length;
        int[] dp = new int[max+1];
        
        for (int num : nums) dp[num] += num;
        dp[dp.length-2] = Math.max(dp[dp.length-2], dp[dp.length-1]);
        for (int i = dp.length-3; i >= 0; i--) {
            dp[i] = Math.max(dp[i+1], dp[i] + dp[i+2]);
        }
      
        return dp[0];
	}
}
