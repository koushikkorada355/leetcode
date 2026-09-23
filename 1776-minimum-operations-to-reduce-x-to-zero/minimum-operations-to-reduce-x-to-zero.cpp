#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;
        for(int i = 0;i < n;i++){
            total += nums[i];
        }
        int target = total - x;
        if(target < 0){
            return -1;
        }
        int l = 0;
        int sum = 0;
        int ans = -1;
        for(int r = 0;r < n;r++){
            sum += nums[r];
            while(sum > target){
                sum -= nums[l];
                l++;
            }
            if(sum == target){
                ans = max(ans,r - l + 1);
            }
        }
        return ans == -1 ? ans : n - ans;
    }
};
