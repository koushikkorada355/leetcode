#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n = arrivalTime.size();
        for(int i = 0;i < n;i++){
            arrivalTime[i] %= period;
        }
        int maxi = *max_element(lights.begin(),lights.end());
        int ans = 0;
        for(int r : arrivalTime){
            ans = max(ans,r < maxi ? 0 : period - r);
        }
        return ans;
    }
};