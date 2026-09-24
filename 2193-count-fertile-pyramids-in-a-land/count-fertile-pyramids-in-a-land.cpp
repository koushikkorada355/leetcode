#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j = 0;j < m;j++){
            dp[n - 1][j] = grid[n - 1][j];
        }
        int ans = 0;
        for(int i = n - 2;i >= 0;i--){
            for(int j = 0;j < m;j++){
                if(j - 1 < 0 || j + 1 >= m){
                    dp[i][j] = grid[i][j];
                }
                else{
                     dp[i][j] = grid[i][j] 
                             * (1 + min({dp[i + 1][j - 1],dp[i + 1][j],dp[i + 1][j + 1]}));
                }
                ans += dp[i][j] - grid[i][j];
            }
        }
        return ans;
    }
    int countPyramids(vector<vector<int>>& grid) {
        int ans = solve(grid);
        int n = grid.size();
        for(int i = 0;i < n / 2;i++){
            vector<int> t = grid[i];
            grid[i] = grid[n - i - 1];
            grid[n - i - 1] = t;
        }

        return ans + solve(grid);
    }
};