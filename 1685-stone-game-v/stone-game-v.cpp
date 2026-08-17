#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i, int j, vector<int>& stones, vector<int>& prefix,
              vector<vector<int>>& dp) {
        if (i == j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        for (int k = i; k < j; k++) {
            int left = prefix[k + 1] - prefix[i];
            int right = prefix[j + 1] - prefix[k + 1];
            if (left == right) {
                int res = max(solve(i, k, stones, prefix, dp),
                              solve(k + 1, j, stones, prefix, dp)) +
                          left;
                ans = max(ans, res);
            } else if (left < right) {
                int res = solve(i, k, stones, prefix, dp) + left;
                ans = max(ans, res);
            } else {
                int res = solve(k + 1, j, stones, prefix, dp) + right;
                ans = max(ans, res);
            }
        }
        return dp[i][j] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, stoneValue, prefix, dp);
    }
};