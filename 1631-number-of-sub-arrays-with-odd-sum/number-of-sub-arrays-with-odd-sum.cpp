class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        for(int i = 0;i < n;i++){
            arr[i] %= 2;
        }

        int oddSumCount = 0;
        int evenSumCount = 0;
        int res = 0;
        for(int i = 0;i < n;i++){
            if(arr[i] == 1){
                int t = oddSumCount;
                oddSumCount = (evenSumCount + 1) % mod;
                evenSumCount = t;
            }
            else{
                evenSumCount = (evenSumCount + 1) % mod;
            }
            res = (res + oddSumCount) % mod;
        }
        return res;
    }
};