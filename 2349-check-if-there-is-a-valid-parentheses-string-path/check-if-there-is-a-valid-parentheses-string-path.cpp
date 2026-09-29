#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int k, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        k += grid[i][j] == '(' ? 1 : -1;

        if (k < 0) {
            return 0;
        }

        if (i == n - 1 && j == m - 1) {
            return k == 0;
        }

        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        if (i + 1 < n && solve(i + 1, j, k, grid)) {
            return dp[i][j][k] = 1;
        }

        if (j + 1 < m && solve(i, j + 1, k, grid)) {
            return dp[i][j][k] = 1;
        }

        return dp[i][j][k] = 0;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if ((n + m - 1) % 2 != 0) {
            return false;
        }

        dp = vector<vector<vector<int>>>(
            n, vector<vector<int>>(
                m, vector<int>(n + m + 1, -1)
            )
        );

        return solve(0, 0, 0, grid);
    }
};