#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i,int complete,int mode,vector<int>& nums1, vector<int>& nums2,vector<vector<vector<int>>>& dp){
        int n = nums1.size();
        if(i == n){
            return 0;
        }
        if(dp[i][complete][mode] != -1){
            return dp[i][complete][mode];
        }
        int ans = 0;
        int val = mode ? nums2[i] : nums1[i];
        if(complete > 0){
            ans = max(ans,solve(i + 1,complete - 1,1 - mode,nums1,nums2,dp) + val);
        }
        return dp[i][complete][mode] = max(ans,solve(i + 1,complete,mode,nums1,nums2,dp) + val);
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2,-1)));
        return max(solve(0,2,0,nums1,nums2,dp),solve(0,2,1,nums1,nums2,dp));
    }
};