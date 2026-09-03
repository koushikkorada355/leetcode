#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<vector<int>> &mat){
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(mat[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        set<vector<vector<int>>> visited;

        visited.insert(mat);
        queue<vector<vector<int>>> q;
        q.push(mat);

        int ans = 0;
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};

        while(!q.empty()){
            int size = q.size();

            for(int l = 0;l < size;l++){

                mat = q.front();
                q.pop();

                if(check(mat)){
                    return ans;
                }

                for(int i = 0;i < n;i++){
                    for(int j = 0;j < m;j++){
                        vector<vector<int>> arr = mat;
                        arr[i][j] = 1 - arr[i][j];
                        for(int k = 0;k < 4;k++){
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                                continue;
                            }
                            arr[nx][ny] = 1 - arr[nx][ny];
                        }
                        if(visited.count(arr) == 0){
                            visited.insert(arr);
                            q.push(arr);
                        }
                    }
                }   
            }
            ans++;
        }
        return -1;

    }
};