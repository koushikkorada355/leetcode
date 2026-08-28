#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n,0);
        int mini = 1e9;
        for(int i = n - 1;i >= 0;i--){
            right[i] = mini;
            mini = min(mini,arr[i]);
        }
        int maxi = 0;
        int ans = 0;
        for(int i = 0;i < n;i++){
            maxi = max(maxi,arr[i]);
            ans += maxi <= right[i];
        }
        return ans;
    }
};