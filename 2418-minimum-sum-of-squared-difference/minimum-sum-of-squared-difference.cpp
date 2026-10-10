#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        int maxi = 0;

        for(int i = 0; i < n; i++){
            diff[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, diff[i]);
        }

        vector<long long> freq(maxi + 1, 0);
        for(int i = 0; i < n; i++){
            freq[diff[i]]++;
        }

        long long k = (long long)k1 + k2;

        for(int i = maxi; i > 0 && k > 0; i--){
            long long take = min(k, freq[i]);
            freq[i] -= take;
            freq[i - 1] += take;
            k -= take;
        }

        long long ans = 0;
        for(int i = 1; i <= maxi; i++){
            ans += freq[i] * i * i;
        }

        return ans;
    }
};