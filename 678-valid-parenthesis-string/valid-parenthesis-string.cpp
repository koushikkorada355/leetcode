#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i,int k,string& s,vector<vector<int>>& dp){
        int n = s.size();
        if(k < 0){
            return 0;
        }
        if(i == n){
            return k == 0;
        }
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        return dp[i][k] = ((s[i] == '(') && solve(i + 1,k + 1,s,dp)) ||
            ((s[i] == ')' ) && solve(i + 1,k - 1,s,dp))  ||
            ((s[i] == '*' ) && (solve(i + 1,k - 1,s,dp) ||
            solve(i + 1,k + 1,s,dp) || 
            solve(i + 1,k,s,dp)));
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n + 1,-1));
        return solve(0,0,s,dp);
    }
};