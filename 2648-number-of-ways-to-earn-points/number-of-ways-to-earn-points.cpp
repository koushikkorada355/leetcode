#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e9 + 7;
    int ways(int i,int target,vector<vector<int>>& types,vector<vector<int>>& dp){
        int n = types.size();
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(i == n){
            return 0;
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        int res = 0;
        for(int j = 0;j <= types[i][0];j++){
            res = (res + ways(i + 1,target - (j * types[i][1]),types,dp)) % mod;
        }
        return dp[i][target] = res;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<int>> dp(n,vector<int>(target + 1,-1));
        return ways(0,target,types,dp);
    }
}; 