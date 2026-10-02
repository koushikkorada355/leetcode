class Solution {
public:
    void generate(int open,int close, string s,vector<string>& ans,int n){
        if(s.size() == 2 * n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            generate(open + 1,close,s + '(',ans,n);
        }
        if(close < open){
            generate(open,close + 1,s + ')',ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> ans;
        generate(0,0,s,ans,n);
        return ans;
    }
};