#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int m = *max_element(nums.begin(),nums.end());
        m = max(m,upper);
        vector<bool> check(m + 1,true);
        for(int e : nums){
            check[e] = false;
        }
        vector<vector<int>> res;
        int i = lower;
        while(i <= upper){
            if(check[i]){
                int start = i;
                int end = i;
                while(i <= upper && check[i]){
                    end = i;
                    i++;
                }
                res.push_back({start,end});
            }
            i++;
        }
        return res;
    }
};