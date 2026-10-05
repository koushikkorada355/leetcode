#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int idx,int n,int bitmask,vector<vector<int>>& dp){
        if(idx == n + 1){
            return 1;
        }
        if(dp[idx][bitmask] != -1){
            return dp[idx][bitmask];
        }
        int ans = 0;
        for(int i = 1;i <= n;i++){
            int bit = (bitmask >> i) & 1;
            if((bit == 0) && (i % idx == 0 || idx % i == 0)){
                ans = ans + solve(idx + 1,n,bitmask | (1 << i),dp);
            }
        }
        return dp[idx][bitmask] = ans;
    }
    int countArrangement(int n) {
        vector<vector<int>> dp(n + 1,vector<int>((1 << (n + 2)),-1));
        return solve(1,n,0,dp);
    }
};