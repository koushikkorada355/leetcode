#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        unordered_map<int,int> list;

        int m = numsDivide.size();
        int n = nums.size();

        int g = 0;
        for(int i = 0;i < m;i++){
            g = gcd(g,numsDivide[i]);
        }
        sort(nums.begin(),nums.end());

        for(int i = 0;i < n;i++){
            if(g % nums[i] == 0){
                return i;
            }
        }
        return -1;
    }
};