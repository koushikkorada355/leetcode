#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int m = n;
        while(n > 0){
            int d = n % 10;
            sum += d;
            product *= d;
            n /= 10;
        }
        return !(m % (sum + product));
    }
};




 