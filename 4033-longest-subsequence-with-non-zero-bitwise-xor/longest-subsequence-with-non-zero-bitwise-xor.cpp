class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        int zero = 0;
        for(int e : nums){
            xorr ^= e;
            zero += e == 0;
        }
        if(zero == n){
            return 0;
        }
        return xorr != 0 ? n : n - 1;
    }
};