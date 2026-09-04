class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minimum(n);
        int mini = nums[n - 1];
        for(int i = n - 1;i >= 0;i--){
            mini = min(mini,nums[i]);
            minimum[i] = mini;
        }
        int maxi = nums[0];
        for(int i = 0;i < n;i++){
            maxi = max(maxi,nums[i]);
            if(maxi - minimum[i] <= k){
                return i;
            }
        }
        return -1;
    }
};