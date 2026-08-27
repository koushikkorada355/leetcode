#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int idx, string& s, vector<int> freq) {
        int n = s.size();
        for (int i = idx; i < n; i++) {
            int c = s[i] - 'a';
            for (int l = 25; l >= 0; l--) {
                if (freq[l] != 0) {
                    if (c < l) {
                        return true;
                    } else if (c == l) {
                        freq[l]--;
                        break;
                    }
                    else{
                        return false;
                    }
                }
                
            }
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            int c = target[i] - 'a';
            if (freq[c] != 0) {
                freq[c]--;
                if (!check(i + 1, target, freq)) {
                    freq[c]++;
                    int l = 0;
                    for (l = c + 1; l < 26; l++) {
                        if (freq[l] != 0) {
                            freq[l]--;
                            ans.push_back(l + 'a');
                            break;
                        }
                    }
                    if (l == 26) {
                        return "";
                    } else {
                        for (int k = 0; k < 26; k++) {
                            int f = freq[k];

                            ans.append(f, 'a' + k);
                        }
                        return ans;
                    }
                }
            } else {
                int l = 0;
                for (l = c + 1; l < 26; l++) {
                    if (freq[l] != 0) {
                        freq[l]--;
                        ans.push_back(l + 'a');
                        break;
                    }

                }
                if (l == 26) {
                    return "";
                } else {
                    for (int k = 0; k < 26; k++) {
                        int f = freq[k];

                        ans.append(f, 'a' + k);
                    }
                    return ans;
                }
            }
            ans.push_back(target[i]);
        }
        return ans;
    }
};