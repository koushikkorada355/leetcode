#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> arr(n,vector<int>(n,0));
        for(int i = 0;i < n;i++){
          int k = rowShift[i];
          for(int j = 0;j < n;j++){
            arr[i][((j - k) % n + n) % n] = grid[i][j];
          }
        }
        for(int j = 0;j < n;j++){
            int k = colShift[j];
            for(int i = 0;i < n;i++){
                grid[((i - k) % n + n) % n][j] = arr[i][j];
            }
        }
        return grid;
    }
};