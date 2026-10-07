#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    set<string> st;
    int mini = 1e9;
    void solve(int i, int open, int k, string& s, string& t) {
        if (open < 0) {
            return;
        }
        if (i == s.size()) {
            if(open != 0){
                return;
            }
            if (k == mini) {
                st.insert(t);
            } else if (k < mini) {
                mini = k;
                st.clear();
                st.insert(t);
            }
            return;
        }
        solve(i + 1, open, k + 1, s, t);
        t.push_back(s[i]);
        solve(i + 1, open + (s[i] == ')' ? -1 : (s[i] == '(' ? 1 : 0)), k, s,
              t);
        t.pop_back();
    }
    vector<string> removeInvalidParentheses(string s) {
        string t = "";
        solve(0, 0, 0, s, t);
        vector<string> res;
        for (string e : st) {
            res.push_back(e);
        }
        return res;
    }
};