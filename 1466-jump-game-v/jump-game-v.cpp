#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i,int d,vector<int>& arr,vector<int>& dp){
        int n = arr.size();
        if(dp[i] != -1){
            return dp[i];
        }
        int maxi = 1;
        for(int j = i + 1;j <= i + d && j < n;j++){
            if(arr[i] <= arr[j]){
                break;
            }
            maxi = max(maxi,1 + solve(j,d,arr,dp));
        }
        for(int j = i - 1;j >= i - d && j >= 0;j--){
            if(arr[i] <= arr[j]){
                break;
            }
            maxi = max(maxi,1 + solve(j,d,arr,dp));
        }
        return dp[i] = maxi;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int ans = 1;
        vector<int> dp(n,-1);
        for(int i = 0;i < n;i++){
            ans = max(ans,solve(i,d,arr,dp));
        }
        return ans;
    }
};