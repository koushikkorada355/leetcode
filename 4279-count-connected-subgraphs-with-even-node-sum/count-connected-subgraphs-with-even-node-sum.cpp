#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int node,vector<bool>& visited,vector<vector<int>>& list,int mask){
        visited[node] = true;
        for(int nextNode : list[node]){
            if(visited[nextNode] || (!((mask >> nextNode) & 1))){
                continue;
            }
            dfs(nextNode,visited,list,mask);
        }
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> list(n);
        for(vector<int> e : edges){
            int u = e[0];
            int v = e[1];
            list[u].push_back(v);
            list[v].push_back(u);
        }
        int res = 0;
        for(int mask = 0;mask < (1 << n);mask++){
            int bitmask = mask;
            int i = 0;
            int sum = 0;
            while(bitmask > 0){
                sum += (bitmask & 1) && (nums[i]);
                bitmask = bitmask >> 1;
                i++;
            }
            if(sum & 1){
                continue;
            }
            int cnt = 0;
            vector<bool> visited(n,false);
            for(int i = 0;i < n;i++){
                if(((mask >> i) & 1)){
                    if(!visited[i]){
                        cnt++;
                        dfs(i,visited,list,mask);
                    }
                }
            }
            // cout << mask << " " << cnt << " " << sum << "\n"; 
            res += cnt == 1;
        }      
        return res;
    }
};