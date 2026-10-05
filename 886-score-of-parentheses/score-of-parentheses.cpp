class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();

        int res = 0;
        stack<char> st;
        int score = 1;
        for(int i = 0;i < n;i++){
            if(s[i] == '('){
                score *= 2;
                continue;
            }
            score /= 2;  
            res += score;
            while(i + 1 < n && s[i + 1] == ')'){
                score /= 2;
                i++;
            }
        

        }
        return res;
    }
};