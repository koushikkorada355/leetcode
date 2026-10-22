#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n = word.size();

        int res = 0;
        bool prev = false;
        for(int i = 1;i < n;i++){
        
          if(prev){
            prev = false;
            continue;
          }
          if(abs(word[i] - word[i - 1]) <= 1){
            res++;
            prev = true;
          }
          else{
            prev = false;
          }
        }
        return res;
    }
};