#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int lowestOld = 1e9 + 1;
        int olds = 0;
        int evens = 0;
        for(int i = 0;i < n;i++){
            lowestOld = nums1[i] & 1 ? min(lowestOld,nums1[i]) : lowestOld;
            olds += nums1[i] & 1;
            evens += (nums1[i] & 1) == 0;
        }
        if(olds == 0 || evens == 0){
            return true;
        }

        for(int i = 0;i < n;i++){
            if(nums1[i] & 1){
                continue;
            }
            if(nums1[i] < lowestOld){
                return false;
            }
        }
        return true;

    }
};