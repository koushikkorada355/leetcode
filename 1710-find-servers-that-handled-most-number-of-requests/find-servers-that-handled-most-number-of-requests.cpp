#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<vector<int>,vector<vector<int>>,greater<>> task;

        set<int> available;

        for(int i = 0;i < k;i++){
          available.insert(i);
        }
        vector<int> res(k,0);
        int busy = 0;
        for(int i = 0;i < arrival.size();i++){
          while(!task.empty() && task.top()[0] <= arrival[i]){
            vector<int> curr = task.top();
            task.pop();
            available.insert(curr[1]);
          }
          if(available.empty()){
            continue;
          }
          int sev = -1;
          auto it = available.lower_bound(i % k);
          if(it != available.end()){
            sev = *it;
          }
          else{
            sev = *available.begin();
          }
          available.erase(sev);
          res[sev]++;
          busy = max(busy,res[sev]);
          task.push({arrival[i] + load[i],sev});
        }
        vector<int> ans;
        for(int i = 0;i < k;i++){
          if(res[i] == busy){
            ans.push_back(i);
          }
        }
        return ans;
    }
};