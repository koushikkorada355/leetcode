class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int ans = 0;
        int cnt = 0;
        for(int i = 0;i < n;i++){
            cnt += s[i] == '(';
            cnt -= s[i] == ')';
            ans = max(ans,cnt);
        }
        return ans;
        
    }
};