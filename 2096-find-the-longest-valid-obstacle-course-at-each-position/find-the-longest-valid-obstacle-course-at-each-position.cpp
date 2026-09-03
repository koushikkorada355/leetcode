#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans;
        vector<int> res(n,0);
        ans.push_back(obstacles[0]);
        res[0] = 1;
        for(int i = 1;i < n;i++){
            if(ans.back() <= obstacles[i]){
                ans.push_back(obstacles[i]);
                res[i] = ans.size();
                continue;
            }
            int idx = upper_bound(ans.begin(),ans.end(),obstacles[i]) - ans.begin();
            res[i] = idx + 1;

            // cout << idx << " ";
             ans[idx] = obstacles[i];
        }
        return res;
    }
};