class Solution {
public:
    bool check(vector<vector<int>>& tasks,int energy){
        int n = tasks.size();
        for(int i = 0;i < n;i++){
            if(energy < tasks[i][1]){
                return false;
            }
            energy -= tasks[i][0];
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[&](vector<int>& a,vector<int>& b){
            return a[1] - a[0] > b[1] - b[0];
        });

        int l = 1;
        int r = 1e9;
        int ans = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;

            if(check(tasks,mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};