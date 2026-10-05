#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i,int j,string& s,string& t){
        int n = s.size();
        int m = t.size();
        if(j == m){
            return 0;
        }
        int ans = solve(i,j + 1,s,t);
        int op = 0;
        for(int k = 0;i + k < n && j + k < m;k++){
            op += s[i + k] != t[j + k];
            ans += op == 1;
            if(op > 1){
                return ans;
            }
        }
        return ans;
    }
    int countSubstrings(string s, string t) {
        int ans = 0;
        int n = s.size();
        for(int i = 0;i < n;i++){
            int val =  solve(i,0,s,t);
            ans += val;
        }
        return ans;
    }
};