#include<bits/stdc++.h>
using namespace std;
class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i = 0;i < n;i++){
            parent[i] = i;
        }
    }
    int find(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
   }
   bool unite(int u,int v){
      int pu = find(u);
      int pv = find(v);
      if(pu == pv){
        return true;
      }
      if(rank[pu] < rank[pv]){
        parent[pu] = pv;
      }
      else if(rank[pu] > rank[pv]){
        parent[pv] = pu;
      }
      else{
        parent[pv] = pu;
        rank[pu]++;
      }
      return false;
   }
};
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        DSU dsu(n);
        vector<int> copy(n);
        for(int i = 0;i < n;i++){
            copy[i] = i;
        }
        sort(copy.begin(),copy.end(),[&](int a,int b){
            return nums[a] < nums[b];
        });
        for(int i = 1;i < n;i++){
            if((nums[copy[i]] - nums[copy[i - 1]]) <= limit){
                dsu.unite(copy[i],copy[i - 1]);
            }
        }
        unordered_map<int,queue<int>> list;
        for(int i = 0;i < n;i++){
            int parent = dsu.find(copy[i]);
            list[parent].push(nums[copy[i]]);

        }
        vector<int> ans;
        for(int i = 0;i < n;i++){
            int parent = dsu.find(i);
            int val = list[parent].front();
            list[parent].pop();
            ans.push_back(val);
        }
        return ans;
    }
};