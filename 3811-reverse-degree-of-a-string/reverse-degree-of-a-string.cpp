class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int sum = 0;
        for(int i = 0;i < n;i++){
            char c = s[i];
            sum += (26 - (c - 'a')) * (i + 1);
        }
        return sum;
    }
};