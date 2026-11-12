#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int target,int b,vector<int>& composition,vector<int>& stock,vector<int>& cost){
        long long budget = b;

        int n = composition.size();
        for(int i = 0;i < n;i++){
            budget -= max(0LL,(long long)(target * (long long)composition[i]) - (long long)stock[i]) * (long long)cost[i];
            if(budget < 0){
                return false;
            }
        }
        return true;
    }
    int binarySearch(int budget,vector<int>& composition,vector<int>& stock,vector<int>& cost){
        int l = 0;
        int r = 1e9;
        int ans = 0;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(check(mid,budget,composition,stock,cost)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int res = 0;

        for(int i = 0;i < k;i++){
            res = max(res,binarySearch(budget,composition[i],stock,cost));
        }
        return res;
    }
};
