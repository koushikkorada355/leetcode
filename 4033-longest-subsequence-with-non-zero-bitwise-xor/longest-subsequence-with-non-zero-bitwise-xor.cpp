class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        int zeros = 0;
        for(int e : nums){
            xorr ^= e;
            zeros += e == 0;
        }
        if(zeros == n){
            return 0;
        }
        return xorr != 0 ? n : n - 1;
    }
};