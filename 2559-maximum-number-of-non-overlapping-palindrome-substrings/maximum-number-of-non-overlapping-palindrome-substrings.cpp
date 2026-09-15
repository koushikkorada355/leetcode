#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(int idx, string& s, int k, vector<vector<bool>>& palindrome,vector<int>& dp) {
        int n = s.size();
        if (idx == n) {
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int ans = solve(idx + 1, s, k, palindrome,dp);
        for (int i = idx + k - 1; i < n; i++) {
            // string t = s.substr(idx, i - idx + 1);
            if (palindrome[idx][i]) {
                ans = max(ans, 1 + solve(i + 1, s, k, palindrome,dp));
            }
        }
        return dp[idx] = ans;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                if (i == j) {
                    palindrome[i][j] = true;
                    continue;
                }
                if (s[i] == s[j] &&
                    ((j - i + 1 <= 3) || (palindrome[i + 1][j - 1]))) {
                    palindrome[i][j] = true;
                }
            }
        }
        vector<int> dp(n,-1);
        return solve(0, s, k, palindrome,dp);
    }
};