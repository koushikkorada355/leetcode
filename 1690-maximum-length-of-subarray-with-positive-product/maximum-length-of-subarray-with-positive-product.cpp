#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& nums){
        int n = nums.size();
        int first = -1;
        int cnt = 0;
        int res = 0;
        int start = 0;
        for(int i = 0;i < n;i++){
            cnt += nums[i];
            if(nums[i] == -1){
                cnt = 0;
                first = -1;
                start = i + 1;
                continue;
            }
            first = first == -1 && nums[i] ? i : first;
            res = max(res,cnt % 2 == 0 ? i - start + 1 : i - first);
        }
        return res;
    }
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++){
            nums[i] = nums[i] == 0 ? -1 : nums[i] < 0;
        }
        int res = solve(nums);
        return max(res,solve(nums));
    }
};