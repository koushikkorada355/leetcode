class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int a=nums[i];
            int more=target-a;
            if(mpp.find(more)!=mpp.end()){
                return {i,mpp[more]};
            }
            mpp[nums[i]]=i;
        }
        return {-1,-1};
        
    }
};