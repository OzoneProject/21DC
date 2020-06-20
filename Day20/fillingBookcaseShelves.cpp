int minHeightShelves(vector<vector<int>>& b, int sh_w) {
  vector<int> dp(b.size() + 1);
  for (int p = 1; p <= b.size(); ++p) {
    for (int i = p, w = 0, h = 0; i > 0 && w + b[i - 1][0] <= sh_w; --i) {
      w += b[i - 1][0];
      h = max(h, b[i - 1][1]);
      dp[p] = min(dp[p] == 0 ? INT_MAX : dp[p], dp[i - 1] + h);
    }
  }
  return dp.back();
}