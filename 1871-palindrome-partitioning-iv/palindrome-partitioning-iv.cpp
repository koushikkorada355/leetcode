#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int idx,int k,vector<vector<int>>& palindrome,vector<vector<int>>& dp){
        int n = palindrome.size();
        if(k < 0){
            return 0;
        }
        if(idx == n){
            return k == 0;
        }
        if(dp[idx][k] != -1){
            return dp[idx][k];
        }
        for(int i = idx;i < n;i++){
            if(palindrome[idx][i] && solve(i + 1,k - 1,palindrome,dp)){
                return 1;
            }
        }
        return dp[idx][k] = 0;
    }
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<int>> palindrome(n,vector<int>(n,false));
        for(int i = 0;i < n;i++){
            for(int j = 0;j <= i;j++){
                if(i - j + 1 > 2){
                    palindrome[j][i] = s[i] == s[j] && palindrome[j + 1][i - 1];
                }
                else{
                    palindrome[j][i] = s[i] == s[j];
                }
            }
        }
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return solve(0,3,palindrome,dp);
    }
};