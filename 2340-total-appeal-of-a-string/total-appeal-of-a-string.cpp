#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long appealSum(string s) {
        long long n = s.size();
        vector<long long> dp(26,0);
        vector<int> left(26,0);
        long long total = 0;
        for(long long l = 0;l < n;l++){
            total = total + (l + 1) * (n - l);
        }
        for(int i = 0;i < n;i++){
            int c = s[i] - 'a';
            left[c] = (i + 1);
            dp[c] += (i + 1);
            for(int k = 0;k < 26;k++){
                total = total - dp[k] + left[k];
            }
        }
        return total;
    }
};