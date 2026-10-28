class Solution {
public:
    int solve(int i, int j, int xr,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {

        int m = grid.size(), n = grid[0].size();

        xr ^= grid[i][j];

        if (i == m - 1 && j == n - 1)
            return xr;

        if (dp[i][j][xr] != -1)
            return dp[i][j][xr];

        int ans = INT_MAX;

        if (i + 1 < m)
            ans = min(ans, solve(i + 1, j, xr, grid, dp));

        if (j + 1 < n)
            ans = min(ans, solve(i, j + 1, xr, grid, dp));

        return dp[i][j][xr] = ans;
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int MAX_XOR = 1024;

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(
                n, vector<int>(MAX_XOR, -1)
            )
        );

        return solve(0, 0, 0, grid, dp);
    }
};