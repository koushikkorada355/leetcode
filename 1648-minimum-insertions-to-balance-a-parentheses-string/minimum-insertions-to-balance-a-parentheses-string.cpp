#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int res = 0;
        int close = 0;
        for(int i = n - 1;i >= 0;i--){
            close += s[i] == ')';
            if(s[i] == '('){
                if(close >= 2){
                    close -= 2;
                    res += (close % 2);
                    close += (close % 2);
                }
                else{
                    res += 2 - close;
                    close = 0;
                }
            }
        }
        return res + close / 2 + (close % 2 ? 2 : 0);
    }
};