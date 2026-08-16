class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int i = 0;
        while(num > 0){
            int bit = num & 1;
            if(!bit){
                ans = ans | (1 << i);
            }
            num = num >> 1;
            i++;
        }
        return ans;
    }
};