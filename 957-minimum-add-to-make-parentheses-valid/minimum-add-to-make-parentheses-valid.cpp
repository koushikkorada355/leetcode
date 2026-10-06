class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int ans = 0;
        int open = 0;
        for(int i = 0;i < n;i++){
            open += s[i] == '(';
            if(s[i] == ')'){
                if(open >= 1){
                    open--;
                }
                else{
                    ans++;
                }
            }
        }
        return ans + open;
    }
};