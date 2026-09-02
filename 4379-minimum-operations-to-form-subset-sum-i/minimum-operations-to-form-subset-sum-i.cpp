#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int i,int sum,vector<int>& nums,vector<vector<int>>& dp){
        int n = nums.size();
        if(sum == 0){
            return 0;
        }
        if(sum < 0 || i == n){
            return 1e9 + 7;
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        int ans = 1e9 + 7;
        ans = min(ans,solve(i + 1,sum,nums,dp));
        ans = min(ans,solve(i + 1,sum - nums[i],nums,dp));
        int l = 1;
        for(int x = 2 * nums[i];x <= sum;x *= 2){
            ans = min(ans,(l + solve(i + 1,sum - x,nums,dp)));
            l++;
        }
        l = 1;
        for(int x = nums[i] / 2;x >= 1;x /= 2){
            ans = min(ans,(l + solve(i + 1,sum - x,nums,dp)));
            l++;
        }
        return dp[i][sum] = ans;
    }
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(sum + 1,-1));
        int res = solve(0,sum,nums,dp);
        return res >= 1e9 ? -1 : res; 
    }
};