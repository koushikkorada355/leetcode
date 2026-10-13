#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());

        int i = 0;
        int j = n - 1;
        long long res = 0;
        while(i < j){
            res -= (nums[i] * nums[i]);
            res += (nums[j] * nums[j]);
            
            i++;
            j--;
        }
        return i != j ? res : res + (nums[j] * nums[j]);
    }
};