class Solution {
public:
    long long countCommas(long long n) {
        
        if(n < 1000){
            return 0;
        }
        long long ans = 0;
        long long m = 1000;
        long long c = 1;
        while(m <= n){
            if(n < m * 1000){
                ans += (n - m + 1) * c;
            }
            else{
                ans += (m * 1000 - m) * c;
            }
            // ans += (min(n,m * 1000) - m + 1) * c;
            c++;
            m = m * 1000;
        }
        return ans;
    }
};