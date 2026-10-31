class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, 0)));
        dp[0][0][0]=1;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(j>0){
                        if(grid[i][j-1]==1){
                            dp[i][j][1]+=dp[i][j-1][0]%mod;
                        }
                        else{
                            dp[i][j][1]+=(dp[i][j-1][0]+dp[i][j-1][1])%mod;
                        }
                    }
                    if(i>0){
                        if(grid[i-1][j]==1){
                            dp[i][j][0]+=(dp[i-1][j][1])%mod;
                        }
                        else{
                            dp[i][j][0]+=(dp[i-1][j][0]+dp[i-1][j][1])%mod;
                        }
                    }
            }
        }
        return (dp[n-1][m-1][0]+dp[n-1][m-1][1])%mod;
    }
};