#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string maxNumber(string& a,string& b){
        if(a.size() == b.size()){
            for(int i = 0;i < a.size();i++){
                if(a[i] != b[i]){
                    return a[i] < b[i] ? b : a;
                }
            }
            return a;
        }
        return a.size() < b.size() ? b : a;
    }
    string solve(vector<int>& cost,int target,vector<string>& dp){
        if(target < 0){
            return "0";
        }
        if(target == 0){
           
            return "";
        }
        if(dp[target] != "-"){
            return dp[target];
        }
        string maxi = "0";
        for(int i = 8;i >= 0;i--){
            string res = solve(cost,target - cost[i],dp);
            if(res.size() == 0 || res[0] != '0'){
                char c = (i + 1 + '0');
                res.insert(res.begin(),c);
                maxi = maxNumber(maxi,res);
            }
        }
        return dp[target] = maxi;
    }
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target + 1,"-");
        return solve(cost,target,dp);
        
    }
};