class Solution {
public:
    int solve(int x,int y,vector<vector<int>>& img1,vector<vector<int>>& img2){
        int n = img1.size();
        int cnt = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i + x < 0 || j + y < 0 || i + x >= n || j + y >= n){
                    continue;
                }
                cnt += img1[i + x][j + y] == img2[i][j] && img2[i][j] == 1;
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for(int up = 0;up < n;up++){
            for(int rt = 0;rt < n;rt++){
                ans = max({ans,solve(up,rt,img1,img2),
                           solve(up,-rt,img1,img2),
                           solve(-up,rt,img1,img2),
                           solve(-up,-rt,img1,img2)
                        });
            }
        }
        return ans;
    }
};