class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        int a = 0;
        int b = 0;
        for(int i = 0;i < n;i++){
            if(mini == nums[i] || maxi == nums[i]){
                b = i;
            }
        }
        for(int i = n - 1;i >= 0;i--){
            if(mini == nums[i] || maxi == nums[i]){
                a = i;
            }
        }
        return min({b + 1,n - a,a + n - b + 1});
        

    }
};