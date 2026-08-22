#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longest(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n = matrix.size();
        int m = matrix[0].size();
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 1;
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        for(int k = 0;k < 4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || matrix[nx][ny] <= matrix[i][j]){
                continue;
            }
            ans = max(ans,1 + longest(nx,ny,matrix,dp));
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 1;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                res = max(res,longest(i,j,matrix,dp));
            }
        }
        return res;
    }
};