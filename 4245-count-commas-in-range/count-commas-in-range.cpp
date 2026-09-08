class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        for(int i = 1;i <= n;i++){
            string s = to_string(i);
            ans += (s.size() - 1) / 3;
        }
        return ans;
    }
};