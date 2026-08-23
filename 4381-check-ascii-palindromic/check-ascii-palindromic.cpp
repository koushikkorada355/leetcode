#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindromic(string s) {
        int n = s.size();
        string t = "";
        for(int c : s){
            string k = bitset<8>(c).to_string();
            t += k;
        }
        int i = 0;
        int j = t.size() - 1;
        while(i <= j && t[i] == t[j]){
            i++;
            j--;
        }
        return i > j;
    }
};