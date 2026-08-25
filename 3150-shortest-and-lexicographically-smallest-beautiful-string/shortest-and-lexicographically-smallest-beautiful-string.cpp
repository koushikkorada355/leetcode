#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "9";
        int len = n + 1;
        int l = 0;
        int ones = 0;
        for(int r = 0;r < n;r++){
            ones += s[r] == '1';
            while(ones == k){
                if(r - l + 1 < len){
                    ans = s.substr(l,r - l + 1);
                    len = r - l + 1;
                }
                else if(len == r - l + 1){
                    ans = min(ans,s.substr(l,r - l + 1));
                }
                ones -= s[l] == '1';
                l++;
            }
        }
        return ans[0] == '9' ? "" : ans;
    }
};