#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long mod = 1e9 + 7;
    long long solve(long long p,long long d,long long n,vector<vector<long long>>& dp){
        if(p == n && d == n){
            return 1;
        }
        if(dp[p][d] != -1){
            return dp[p][d];
        }
        long long res = 0;
        if(p < n){
            res = (res + (n - p) * solve(p + 1,d,n,dp)) % mod;
        }
        if(d < p){
            res = (res + (p - d) * solve(p,d + 1,n,dp)) % mod;
        }
        return dp[p][d] = res;
    }
    int countOrders(int n) {
        vector<vector<long long>> dp(n + 1,vector<long long>(n + 1,-1));
        return solve(0,0,n,dp);
    }
};