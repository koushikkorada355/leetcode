#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> factors(int n){
        vector<int> fac;
        for(int i = 1;i * i <= n;i++){
            if(n % i == 0){
                fac.push_back(i);
                if(i != n / i){
                    fac.push_back(n / i);
                }
            }
        }
        return fac;
    }
    bool solve(vector<int>& sorted,vector<int>& nums){
        int k = nums.size();
        int start = 0;
        int minElement = nums[0];
        for(int i = 1;i < k;i++){
            if(minElement > nums[i]){
                start = i;
                minElement = nums[i];
            }
            else if(minElement == nums[i] && nums[i] != nums[i - 1]){
                start = i;
            }
        }
        for(int l = 0;l < k;l++){
            if(nums[start] != sorted[l]){
                return false;
            }
            start = (start + 1) % k;
        }
        return true;
    }
    bool loop(int k,vector<int>& sorted,vector<int>& nums){
        int n = nums.size();
        for(int i = 0;i < n;i += k){
            vector<int> sortSegment(sorted.begin() + i,sorted.begin() + i + k);
            vector<int> segment(nums.begin() + i,nums.begin() + i + k);
            if(!solve(sortSegment,segment)){
                return false;
            }
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        int res = 0;
        vector<int> arr(nums.begin(),nums.end());
        sort(arr.begin(),arr.end());
        vector<int> fac = factors(n);

        for(int f : fac){
            res += loop(f,arr,nums) * f;
        }
        return res;
    }
};