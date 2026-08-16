class Solution {
public:
    int bitwiseComplement(int num) {
        if(num == 0){
            return 1;
        }
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