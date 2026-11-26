class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        int res = 1;
        while(n - stones >= 0){
            n -= stones;
            stones--;
            res = 1 - res;
        }
        return 1 - res;
    }
};