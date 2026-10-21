class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        char maxChar = s[n - 1];
        char c = s[n - 1];
        bool sorted= true;
        for(int i = 0;i < n - 1;i++){
            char curr = s[i];
            if(curr > maxChar){
                maxChar = curr;
            }
            if(c > curr){
                c = curr;
            }
            if(s[i] > s[i + 1]){
                sorted= false;
            }
        }
        if(sorted) return 0;

        if(maxChar > s[n - 1] && n == 2){
            return -1;
            
        }

        if(s[0] == c || s[n - 1] == maxChar){
            return 1;
        }

        if(s[0] == maxChar && (s[n - 1] == c)){
            for(int i = 1;i < n - 1;i++){
                if(s[i] == c || s[i] == maxChar){
                    return 2;
                }
                
            }
            return 3;
        }
        return 2;
    }
};