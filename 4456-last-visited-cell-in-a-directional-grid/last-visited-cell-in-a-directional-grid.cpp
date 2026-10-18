#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int i,int j,vector<vector<bool>>& visited){
        int n = visited.size();
        int m = visited[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j]){
            return false;
        }
        return true;
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
                        //  L R U D
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {-1,1,0,0};

        map<char,int> list;
        list['L'] = 0;
        list['R'] = 1;
        list['U'] = 2;
        list['D'] = 3;

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        int i = 0;
        int j = 0;
        vector<int> res;
        while(check(i,j,visited)){
            visited[i][j] = true;
            res = {i,j};
            char c = grid[i][j];
            i = i + dx[list[c]];
            j = j + dy[list[c]];
        }
        return res;
    }
};