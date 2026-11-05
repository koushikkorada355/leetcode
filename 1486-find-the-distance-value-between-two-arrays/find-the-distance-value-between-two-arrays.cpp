#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int upperBound(int target,vector<int>& arr){
        int n = arr.size();
        int ans = n;
        int l = 0;
        int r = n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(arr[mid] <= target){
                l = mid + 1;
            }
            else{
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        sort(arr2.begin(),arr2.end());
        int res = 0;
        for(int i = 0;i < n;i++){
            int l = upperBound(arr1[i] - d - 1,arr2);
            int r = upperBound(arr1[i] + d,arr2);
            res += (r - l == 0);
        }
        return res;
    }
};