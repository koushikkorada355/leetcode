#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> row(n,0);
        vector<int> col(m,0);

        for(int i = 0;i < n;i++){
          for(int j = 0;j < m;j++){
            row[i] += grid[i][j];
            col[j] += grid[i][j];
          }
        }
        int res = 0;

        for(int i = 0;i < n;i++){
          for(int j = 0;j < m;j++){
             res += (row[i] > 1 || col[j] > 1) * grid[i][j];
          }
        }
        return res;
    }
};