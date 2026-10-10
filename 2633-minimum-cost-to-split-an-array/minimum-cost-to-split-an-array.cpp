#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int idx,int k,vector<int>& nums,vector<int>& dp){
        int n = nums.size();
        if(idx == n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int res = 1e9 + 1000;
        unordered_map<int,int> list;
        unordered_map<int,int> mpp;
        for(int i = idx;i < n;i++){
            int e = nums[i];
            list[mpp[e]]--;
            mpp[e]++;
            list[mpp[e]]++;
            res = min(res,solve(i + 1,k,nums,dp) + k + (i - idx + 1 - list[1]));
        }
        return dp[idx] = res;
    }
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(0,k,nums,dp);
    }
};