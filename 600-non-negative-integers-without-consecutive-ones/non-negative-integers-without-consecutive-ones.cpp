#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i,int p,int tight,string& s,vector<vector<vector<int>>>& dp){
        int n = s.size();
        if(i == n){
            return 1;
        }
        if(dp[i][p][tight] != -1){
            return dp[i][p][tight];
        }
        int res = 0;
        int lb = 0;
        int ub = !tight ? 1 : s[i] - '0';
        for(int d = lb;d <= ub;d++){
            if(d == 1 && p == 1){
                continue;
            }
            res = res + solve(i + 1,d,tight && (d == s[i] - '0'),s,dp);
        }
        return dp[i][p][tight] = res;
    }
    int findIntegers(int n) {
        string s = "";
        while(n > 0){
            int bit = n & 1;
            s += bit + '0';
            n = n >> 1;
        }
        int m = s.size();
        reverse(s.begin(),s.end());
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(0,0,true,s,dp);
    }
};