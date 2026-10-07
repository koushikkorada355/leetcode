class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int open = 0;
        string res = "";
        for(int i = 0;i < n;i++){
            open += s[i] == '(';
            open -= s[i] == ')';
            if(s[i] == '(' && open > 1){
                res += s[i];
            }
            if(s[i] == ')' && open > 0){
                res += s[i];
            }
        }
        return res;
    }
};