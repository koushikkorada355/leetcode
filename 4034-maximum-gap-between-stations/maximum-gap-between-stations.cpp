#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();
        int i = 0;
        int j = 0;
        vector<int> left(n,0);
        vector<int> right(n,0);
        while(i < n){
            if(skill[i] == station[j]){
                left[i] = j;
                i++;
            }
            j++;
        }
        i = n - 1;
        j = m - 1;
        while(i >= 0){
            if(skill[i] == station[j]){
                right[i] = j;
                i--;
            }
            j--;
        }
        int ans = 0;
        for(int i = 0;i < n - 1;i++){
            ans = max(ans,right[i + 1] - left[i]);
        }
        return ans;
    }
};