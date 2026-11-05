#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end());
        int endTime = 0;
        for(int i = 0;i < logs.size();i++){
            endTime = max(endTime,logs[i][1]);
        }

        for(int q : queries){
            endTime = max(endTime,q);
        }
        vector<int> prefix(endTime + x + 2,0);

        for(int i = 0;i < logs.size();i++){
            int time = logs[i][1];
            int server  = logs[i][0];
            prefix[time]++;
            int end = i + 1 < logs.size() && server == logs[i + 1][0] ? min(time + x + 1,logs[i + 1][1]) : time + x + 1;
            prefix[end]--;
        }
        int cnt = 0;
        for(int i = 0;i < prefix.size();i++){
            cnt += prefix[i];
            prefix[i] = cnt;
        }
        vector<int> res;
        for(int q : queries){
            res.push_back(n - prefix[q]);
        }
        return res;
    }
};