#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = -1;
        int n = drones.size();
        int mini = 1e9;
        int i = 0;
        for(int i = n - 1;i >= 0;i--){
            vector<int> d = drones[i];
            int dis = abs(d[0] - target[0]) + abs(d[1] - target[1]);
            bool check = dis <= d[2] && dis <= mini;
            ans =  check ? i : ans;
            mini = check ? dis : mini;
        }
        return ans;
    }
};