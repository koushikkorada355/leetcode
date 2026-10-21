#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();
        vector<long long> prefix(n,0);
        vector<long long> suffix(n,0);
        for(int i = 1;i < n;i++){
           prefix[i] = prefix[i - 1] + (s[i] != s[i - 1]) * i;
        }

        for(int i = n - 2;i >= 0;i--){
          suffix[i] = suffix[i + 1] + (s[i] != s[i + 1]) * (n - i - 1);
        }

        long long res = LLONG_MAX;
        for(int i = 0;i < n;i++){
          res = min(res,prefix[i] + suffix[i]);
        }
        return res;
    }
};