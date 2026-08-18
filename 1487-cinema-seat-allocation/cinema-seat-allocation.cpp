#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>> list;
        for(vector<int> e : reservedSeats){
          int i = e[0];
          int j = e[1];
          list[i].insert(j);
        }
        int ans = 0;
        for(auto it : list){
            set<int> st = it.second;
            bool a = !(st.count(2) || st.count(3) || st.count(4) || st.count(5));
            bool b = !(st.count(6) || st.count(7) || st.count(8) || st.count(9));
            bool c = !(st.count(4) || st.count(5) || st.count(6) || st.count(7));
            ans += a + b;
            ans += (a + b == 0) * c;
        }
        return ans + (n - list.size()) * 2;
    }
};