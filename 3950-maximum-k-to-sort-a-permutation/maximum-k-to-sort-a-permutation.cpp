class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int res = (1 << 20) - 1;
        bool sorted = true;
        for(int i = 0;i < n;i++){
            if(i != nums[i]){
                sorted = false;
                res = res & nums[i];
            }
        }
        return sorted ? 0 : res;
    }
};