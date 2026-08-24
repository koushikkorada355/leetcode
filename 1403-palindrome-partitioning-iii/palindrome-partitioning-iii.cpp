#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i,string s,vector<vector<int>>& score,int k,vector<vector<int>>& dp){
        int n = s.size();
        if(k < 0){
            return 1e8;
        }
        if(i == n){
            if(k > 0){
                return 1e8;
            }
            return 0;
        }
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        int ans = 1e8;
        for(int j = i;j < n;j++){
            ans = min(ans,solve(j + 1,s,score,k - 1,dp) + score[i][j]);
        }
        return dp[i][k] = ans;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> score(n,vector<int>(n,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                score[j][i] = s[i] != s[j];
                if(i - j + 1 > 2){
                    score[j][i] += score[j + 1][i - 1];
                }
            }
        }
        vector<vector<int>> dp(n,vector<int>(k + 1,-1));
        return solve(0,s,score,k,dp);
    }
};