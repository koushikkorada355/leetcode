#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string create(long long n){
        string s = "";

        while(n > 0){
            s += (n % 10) + '0';
            n = n / 10;
        }
        for(long long i = s.length();i < 16;i++){
            s += '0';
        }
        reverse(s.begin(),s.end());
        return s;
    }
    long long solve(long long i,long long tight,long long p,string& s,vector<bool>& visited,vector<vector<vector<long long>>>& dp){
        if(i == 16){
            return 1;
        }
        if(dp[i][tight][p] != -1){
            return dp[i][tight][p];
        }
        long long lower = visited[i] ? p : 0;
        long long upper = tight ? s[i] - '0' : 9;
        long long res = 0;
        for(long long d = lower;d <= upper;d++){
            res += solve(i + 1,tight && (d == upper),visited[i] ? d : p,s,visited,dp);
        }
        return dp[i][tight][p] = res;

    }
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        vector<bool> visited(16,0);
        long long i = 0;
        long long j = 0;
        visited[0] = 1;
        for(long long l = 0;l < 6;l++){
            i += directions[l] == 'D';
            j += directions[l] == 'R';

            long long cord = 4 * i + j;
            visited[cord] = 1;
        }
        string r_string = create(r);
        string l_string = create(l - 1);
        vector<vector<vector<long long>>> dp1(16,vector<vector<long long>>(2,vector<long long>(10,-1)));
        vector<vector<vector<long long>>> dp2(16,vector<vector<long long>>(2,vector<long long>(10,-1)));
        return solve(0,1,0,r_string,visited,dp1) - solve(0,1,0,l_string,visited,dp2);

    }
};