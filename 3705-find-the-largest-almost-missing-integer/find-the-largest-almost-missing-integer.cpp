#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == k){
            return *max_element(nums.begin(),nums.end());
        }
        unordered_map<int,int> list;
        for(int i = 0;i < n;i++){
            list[nums[i]]++;
        }
        int ans = -1;
        if(k == 1){
            for(int i = 0;i < n;i++){
                if(list[nums[i]] == 1){
                    ans = max(ans,nums[i]);
                }
            }
            return ans;
        }
        if(list[nums[0]] == 1){
            ans = nums[0];
        }
        if(list[nums[n - 1]] == 1){
            ans = max(ans,nums[n - 1]);
        }
        return ans;
    }
};