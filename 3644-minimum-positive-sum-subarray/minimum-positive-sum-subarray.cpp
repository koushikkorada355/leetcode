#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& nums,int k){
      int sum = 0;
      for(int i = 0;i < k;i++){
        sum += nums[i];
      }
      int res = 1e9;
      if(sum > 0){
        res = sum;
      }
      for(int i = k;i < nums.size();i++){
         sum -= nums[i - k];
         sum += nums[i];
         if(sum > 0){
            res = min(res,sum);
         }
         
      }
      return res;
    }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int res = 1e9;

        for(int i = l;i <= r;i++){
          res = min(res,solve(nums,i));
        }

        return res == 1e9 ? -1 : res;
    }
};