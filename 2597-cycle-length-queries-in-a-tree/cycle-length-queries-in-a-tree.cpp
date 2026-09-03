#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();

        vector<int> ans(m,0);

        for(int i = 0;i < m;i++){

            int l = queries[i][0];
            int r = queries[i][1];

            int len = 1;
            while(l != r){
                if(l < r){
                    r = r / 2;
                }
                else{
                    l = l / 2;
                }
                len++;
            }

            ans[i] = len;
        }
        return ans;
    }
};