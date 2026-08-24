#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(vector<int>& letters,vector<int>& freq,vector<int>& score){
        int ans = 0;
        for(int i = 0;i < 26;i++){
            if(letters[i] > freq[i]){
                return -1;
            }
            ans += letters[i] * score[i];
        }
        return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        int ans = 0;
        vector<int> freq(26,0);
        for(char c : letters){
            freq[c - 'a']++;
        }
        for(int i = 0;i < (1 << n);i++){
            int mask = i;
            int j = 0;
            vector<int> letter(26,0);
            while(mask > 0){
                int bit = mask & 1;
                if(bit){
                    for(char c : words[j]){
                        letter[c - 'a']++;
                    }
                }
                mask = mask >> 1;
                j++;
            }
            int res = check(letter,freq,score);
            ans = max(ans,res);
            // cout << i << " ";
        }
        return ans;
    }
};