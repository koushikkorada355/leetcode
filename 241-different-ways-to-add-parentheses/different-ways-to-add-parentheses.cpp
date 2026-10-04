#include <bits/stdc++.h>
using namespace std;
class Solution {
public: 
    void expend(char op,vector<int>& first,vector<int>& second,vector<int>& res){

        for(int f : first){
            for(int s : second){
                if(op == '+'){
                    res.push_back(f + s);
                }
                else if(op == '-'){
                    res.push_back(f - s);
                }
                else{
                    res.push_back(f * s);
                }
            }
        }
    }
    vector<int> solve(int i,int j,string& s){
        if(j - i <= 1){
            if(j - i == 0){
                return {s[j] - '0'};
            }
            return {(s[i] - '0') * 10 + (s[j] - '0')};
        }
        vector<int> res;
        for(int k = i;k <= j;k++){
            if(!isdigit(s[k])){
                vector<int> first = solve(i,k - 1,s);
                vector<int> second = solve(k + 1,j,s);
                expend(s[k],first,second,res);
            }
        }
        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        return solve(0,n - 1,expression);
    }
};