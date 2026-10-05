#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int i,int n,vector<int>& dp){
        if(i >= n){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        return dp[i] = (solve(i + 1,n,dp) + solve(i + 2,n,dp)) % mod;
    }
    int countHousePlacements(int n) {
        vector<int> dp(n,-1);
        long long val = solve(0,n,dp);
        return ((val % mod) * (val % mod)) % mod;   
    }
};