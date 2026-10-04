#include <bits/stdc++.h>
using namespace std;
class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> weight;
    DSU(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        weight.resize(n,131071);
        for(int i = 0;i < n;i++){
            parent[i] = i;
        }
    }
    int find(int i){
        if(i == parent[i]){
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    bool unite(vector<int>& edge){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        int pu = find(u);
        int pv = find(v);
        // cout << u << " " << v << " " << wt << "-";
        if(pu == pv){
            weight[pu] = wt & weight[pu];
            // cout << weight[pu] << "\n";
            return true;
        }
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
            weight[pv] = weight[pv] & weight[pu] & wt; 
            // cout << weight[pv] << "\n";
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
            weight[pu] = weight[pv] & weight[pu] & wt;
            // cout << weight[pu] << "\n";
        }
        else{
            parent[pu] = pv;
            // cout << (wt & weight[pu])<< "\n";
            weight[pv] = weight[pv] & weight[pu] & wt;
            
            rank[pv]++;
        }
        return false;
    }

};
class Solution {
public:
    vector<int> minimumCost(int n,vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for(vector<int> e : edges){
            dsu.unite(e);
            
        }

        vector<int> res;
        for(vector<int>& q : query){
            int pu = dsu.find(q[0]);
            int pv = dsu.find(q[1]);

            int val = pu == pv ? dsu.weight[pu] : -1;
            res.push_back(val);
        }
        return res;

    }
};