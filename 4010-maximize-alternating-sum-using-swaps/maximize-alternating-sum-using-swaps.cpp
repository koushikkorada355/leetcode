#include<bits/stdc++.h>
using namespace std;
class DSU{
public:
    vector<long long> parent;
    vector<long long> rank;
    DSU(long long n){
        parent.resize(n,0);
        rank.resize(n,0);
        for(long long i = 0;i < n;i++){
            parent[i] = i;
        }
    }

    long long find(long long i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    bool unite(long long u,long long v){
        long long pu = find(u);
        long long pv = find(v);

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
        return true;
    }
};
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        long long n = nums.size();

        DSU dsu(n);
        vector<long long> copy(n,0);
        for(long long i = 0;i < n;i++){
            copy[i] = i;
        }

        sort(copy.begin(),copy.end(),[&](long long a,long long b){
            return nums[a] < nums[b];
        });

        for(vector<int> e : swaps){
            long long u = e[0];
            long long v = e[1];
            dsu.unite(u,v);
        }

        map<long long,deque<long long>> list;

        for(long long i = 0;i < n;i++){
            long long parent = dsu.find(copy[i]);
            list[parent].push_back(nums[copy[i]]);
        }

        long long ans = 0;
        for(long long i = 0;i < n;i++){
            long long parent = dsu.find(i);
            if(i & 1){
                ans -= list[parent].front();
                list[parent].pop_front();
            }
            else{
                ans += list[parent].back();
                list[parent].pop_back();
            }
        }
        return ans;
    }
};