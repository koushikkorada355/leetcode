class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // prefix sums
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        vector<int> dp(n);

        // Base case
        dp[n - 1] = stones[n - 1];

        // Take / Skip
        for (int i = n - 2; i >= 1; i--) {
            int take = stones[i] - dp[i + 1];
            int skip = dp[i + 1];

            dp[i] = max(take, skip);
        }

        return dp[1];
    }
};