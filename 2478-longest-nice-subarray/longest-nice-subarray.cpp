#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void addNumber(int n,int m,vector<int>& dp){
        int i = 0;
        while(n > 0){
            int bit = n & 1;

            dp[i] += (bit * m);

            n = n >> 1;
            i++;
        }
    }
    bool check(vector<int>& dp){
        for(int i = 0;i < 30;i++){
            if(dp[i] > 1){
                return true;
            }
        }
        return false;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(30,0);
        int res = 1;
        int l = 0;
        for(int r = 0;r < n;r++){
            addNumber(nums[r],1,dp);
            while(check(dp)){
                addNumber(nums[l],-1,dp);
                l++;
            }
            res = max(res,r - l + 1);
        }
        return res;
    }
};