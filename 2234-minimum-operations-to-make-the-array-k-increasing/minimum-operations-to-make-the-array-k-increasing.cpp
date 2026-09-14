#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int start,vector<int>& arr,int k){
        int n = arr.size();
        vector<int> nums;
        nums.push_back(arr[start]);
        for(int i = start + k;i < n;i += k){
            if(nums.back() <= arr[i]){
                nums.push_back(arr[i]);
                continue;
            }
            int idx = upper_bound(nums.begin(),nums.end(),arr[i]) - nums.begin();
            nums[idx] = arr[i];
        }
        return nums.size();
    }
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0;i < k;i++){
            ans += solve(i,arr,k);
        }
        return n - ans;
    }
};