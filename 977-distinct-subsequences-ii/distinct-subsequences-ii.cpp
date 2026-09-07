#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    int mod = 1e9 + 7;
    int solve(int idx,string& s,vector<int>& dp){
        int n = s.size();
        int ans = idx != 0;
        if(dp[idx] != -1){
            return dp[idx];
        }
        vector<bool> letters(26,false);

        for(int i = idx;i < n;i++){
            if(letters[s[i] - 'a']){
                continue;
            }
            letters[s[i] - 'a'] = true;
            ans = (ans + solve(i + 1,s,dp)) % mod;
        }
        return dp[idx] = ans;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n + 1,-1);
        return solve(0,s,dp);
    }
};