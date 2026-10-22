#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool operation(vector<int>& nums,int m,int start){
      int n = nums.size();

      for(int l = 0;l < n;l++){
        if(nums[start] != l){
          return false;
        }
        start = (start + m + n) % n;
      }
      return true;
    }
    int startIndex(vector<int>& nums){
      int n = nums.size();

      for(int i = 0;i < n;i++){
        if(nums[i] == 0){
          return i;
        }
      }
      return 0;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int start = startIndex(nums);
        int ans = 1e9;

        bool op1 = operation(nums,1,start);
        bool op2 = operation(nums,-1,start);
        if(!op1 && !op2){
          return -1;
        }

        if(op1){
          ans = min(start,n - start + 2);
        }
        if(op2){
          ans = min({ans,start + 2,n - start});
        }
        return ans;
    }
};