#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        long long m = servers.size();
        long long n = tasks.size();
        priority_queue<vector<long long>,vector<vector<long long>>,greater<>> available;

        priority_queue<vector<long long>,vector<vector<long long>>,greater<>> task;

        for(long long i = 0;i < m;i++){
            available.push({servers[i],i});
        }
        vector<int> res(n,0);

        for(long long j = 0;j < n;j++){

            while(!task.empty() && task.top()[0] <= j){
                vector<long long> curr = task.top();
                task.pop();
                available.push({servers[curr[2]],curr[2]});
            }

            if(available.empty() && !task.empty()){
                vector<long long> next = task.top();
                res[j] = next[2];
                task.pop();
                task.push({next[0] + tasks[j],servers[next[2]],next[2]});
            }
            else{
                vector<long long> avail = available.top();
                available.pop();
                res[j] = avail[1];
                task.push({j + tasks[j],servers[avail[1]],avail[1]});
            }
        }
        return res;
    }
}; 