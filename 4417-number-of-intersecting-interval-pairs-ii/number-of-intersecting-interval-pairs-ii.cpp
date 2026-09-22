#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long lowerBound(vector<vector<int>>& intervals,vector<int>& copy,int i){
        int l = 0;
        int r = i - 1;
        int target = intervals[copy[i]][0];
        int ans = i;
        while(l <= r){
            int mid = l + (r - l) / 2;

            if(intervals[copy[mid]][1] >= target){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return i - ans;


    }
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> copy(n,0);

        for(int i = 0;i < n;i++){
            copy[i] = i;
        }

        sort(copy.begin(),copy.end(),[&](int a,int b){
            return intervals[a][1] < intervals[b][1];
        });

        long long ans = 0;
        for(int i = 0;i < n;i++){
             ans += lowerBound(intervals,copy,i);
        }
        return ans;
    }
};