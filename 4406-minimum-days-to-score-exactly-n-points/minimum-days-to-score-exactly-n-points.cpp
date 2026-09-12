class Solution {
public:
    int solve(int score,int n,vector<int>& dp){
        // if(score > n){
        //     return 1e9;
        // }
        if(score == n){
            return 0;
        }
        if(dp[score] != -1){
            return dp[score];
        }
        int sum = 0;
        int curr = 1;
        int ans = 1e9;
        while(score + sum + curr <= n){
            sum += curr;
            ans = min(ans,1 + curr + solve(score + sum,n,dp));
            curr++;
        }
        return dp[score] = ans;
    }
    int minDays(int n) {
        vector<int> dp(n + 1,-1);
       return  solve(0,n,dp) - 1;
    }
};