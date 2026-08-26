#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int n,int mask,int j,vector<int>& nums){
        int m = nums.size();
        if(n == 0){
            return 1;
        }
       
        int cnt = 0;
        int i = 0;
        for(int i = 0;i < m;i++){
            int bit = mask & (1 << i);
            if(!bit){
                if(i > 0 && nums[i] == nums[i - 1] && (mask & (1 << (i - 1))) == 0){
                    continue;
                }
                int val = nums[j] + nums[i];
                int sval = sqrt(val);
                if(sval * sval == val){
                    cnt += solve(n - 1,mask | (1 << i),i,nums);
                }
            }
            
        }
        return cnt;
    }
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            cnt += solve(n - 1,1 << i,i,nums);
        }
        return cnt;
    }
};