#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> prev;
        unordered_map<int,int> list;

        for(int i = 0;i < n;i++){
            int e = nums[i];
            if(prev.find(e) != prev.end()){
                list[e] = max(list[e],i - prev[e]);
            }
            prev[e] = i;
        }

        int ans = 0;
        for(auto e : list){
            ans += e.second > 1;
        }

        return prev.size() - ans;

    }
};