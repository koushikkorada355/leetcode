#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestIncrease(vector<int>& nums){
        int n = nums.size();
        int res = 1;
        int cnt = 1;
        for(int i = 1;i < n;i++){
            cnt = nums[i - 1] > nums[i] ? cnt + 1 : 1;
            res = max(res,cnt); 
        }
        return res;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = longestIncrease(nums);
        reverse(nums.begin(),nums.end());
        return max(res,longestIncrease(nums));
    }
};