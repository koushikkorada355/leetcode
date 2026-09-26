#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();

        unordered_map<string,string> list;

        for(vector<string>& k : knowledge){
            list[k[0]] = k[1];
        }

        string res = "";
        int i = 0;
        while(i < n){
            if(s[i] == '('){
                i++;
                string t = "";
                while(i < n && s[i] != ')'){
                    t += s[i];
                    i++;
                }
                i++;
                res += list.find(t) == list.end() ? "?" : list[t]; 
            }
            else{
               res += s[i];
               i++; 
            }
        }
        return res;
    }
};