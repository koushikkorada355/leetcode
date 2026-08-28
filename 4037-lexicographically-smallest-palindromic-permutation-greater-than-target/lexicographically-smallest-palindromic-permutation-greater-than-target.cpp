#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(string target, vector<int> list, char singleCharacter) {
        int n = target.size();
        for (int i = 0; i < n / 2; i++) {
            char c = target[i];
            if (list[c - 'a'] == 0) {
                return false;
            }
            list[c - 'a']--;
        }
        string t = target.substr(0, n / 2);
        if (n & 1) {
            t += singleCharacter;
        }
        reverse(t.begin(), t.end());

        int j = 0;
        for (int i = n / 2; i < n; i++) {
            char c = target[i];
            if (t[j] > c) {
                return true;
            } else if (t[j] < c) {
                return false;
            }
            j++;
        }
        return false;
    }
    string res = "";
    bool solve(string s, int i, string target, vector<int>& list, int greater) {
        int n = target.size();
        if (i == n / 2) {
            if (greater) {
                res = s;
                return true;
            }
            return false;
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (list[ch - 'a'] == 0) {
                continue;
            }
            if (!greater && ch < target[i]) {
                continue;
            }

            list[ch - 'a']--;
            if (solve(s + ch, i + 1, target, list,
                      greater || (ch > target[i]))) {
                return true;
            }
            list[ch - 'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        // if(n & 1){
        //     return "-1";
        // }
        vector<int> list(26, 0);
        for (int i = 0; i < n; i++) {
            list[s[i] - 'a']++;
        }
        int oddCharacters = 0;
        char singleCharacter;
        for (int i = 0; i < 26; i++) {
            oddCharacters += list[i] & 1;
            if (list[i] & 1) {
                singleCharacter = i + 'a';
            }
        }
        if (oddCharacters > 1) {
            return "";
        }
        for (int i = 0; i < 26; i++) {
            list[i] =  list[i] / 2;
        }

        if (check(target, list, singleCharacter)) {
            string k = target.substr(0, n / 2);
            string t = k;
            reverse(t.begin(), t.end());
            if (n & 1) {
                return k + singleCharacter + t;
            }
            return k + t;
        }
        string r = "";
        bool ans = solve(r, 0, target, list, false);
        if (!ans) {
            return "";
        }
        string t = res;
        reverse(t.begin(), t.end());
        if (n & 1) {
            return res + singleCharacter + t;
        }
        return res + t;
    }
};