class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        int open = 0;
        int close = 0;
        int ans = 0;
        for(int i = 0;i < n;i++){
            open += s[i] == '(';
            close += s[i] == ')';

            if(open == close){
                ans = max(ans,2 * close);
            }
            if(close > open){
                open = 0;
                close = 0;
            }
        }
        open = 0;
        close = 0;
        for(int i = n - 1;i >= 0;i--){
            open += s[i] == '(';
            close += s[i] == ')';

            if(open == close){
                ans = max(ans,2 * close);
            }

            if(open > close){
                open = 0;
                close = 0;
            }

        }

        return ans;

    }
};