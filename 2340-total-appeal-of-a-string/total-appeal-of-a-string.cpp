#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        long long ans = 0;
        vector<long long> dp(26,0);
        for(int i = 0;i < n;i++){
            int c = s[i] - 'a';
            dp[c] = (i + 1);
            for(int l = 0;l < 26;l++){
                ans += dp[l];
            }
        }
        return ans;
    }
};