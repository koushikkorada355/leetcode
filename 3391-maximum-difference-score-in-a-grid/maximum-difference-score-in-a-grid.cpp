#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res = -1e9;
        int mini = 1e9;

        vector<vector<int>> dp(n,vector<int>(m,1e9));
        for(int i = 0;i < n;i++){
          for(int j = 0;j < m;j++){
            int mini = 1e9;

            if(i - 1 >= 0){
              mini = dp[i - 1][j];
            }
            if(j - 1 >= 0){
              mini = min(mini,dp[i][j - 1]);
            }
            res = max(res,grid[i][j] - mini);
            dp[i][j] = min(mini,grid[i][j]);
          }
        }
        return res;
    }
};