#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][arr[0] % 2]++;
        for(int i = 1;i < n;i++){
            dp[i][arr[i] % 2]++;

            for(int r = 0;r < 2;r++){

                dp[i][(r + (arr[i] % 2)) % 2] += dp[i - 1][r];
            }
        }
        int mod = 1e9 + 7;
        int ans = 0;
        for(int i = 0;i < n;i++){
            ans = (ans + dp[i][1]) % mod;
        }
        return ans;
    }
};