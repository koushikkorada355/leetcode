#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> seive(){
        int n = 1e5 + 1;
        vector<bool> isPrime(n,true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2;i * i <= n;i++){
            for(int j = i * i;j <= n;j += i){
                isPrime[j] = false;
            }
        }
        return isPrime;
    }
    int addfactors(int n,int cnt,vector<int>& freq,vector<bool>& isPrime){
        for(int i = 1;i * i <= n;i++){
            if(n % i == 0){
                int j = n / i;
                if(isPrime[i]){
                    freq[i]++;
                    cnt += freq[i] == 1;
                }
                if(i != j && isPrime[j]){
                    freq[j]++;
                    cnt += freq[j] == 1;
                }
            }
        }
        return cnt;
    }
    int removefactors(int n,int cnt,vector<int>& freq,vector<bool>& isPrime){
        for(int i = 1;i * i <= n;i++){
            if(n % i == 0){
                int j = n / i;
                if(isPrime[i]){
                    freq[i]--;
                    cnt -= freq[i] == 0;
                }
                if(i != j && isPrime[j]){
                    freq[j]--;
                    cnt -= freq[j] == 0;
                }
            }
        }
        return cnt;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int m = 1e5 + 1;
        int n = nums.size();
        int l = 0;
        int ans = 0;
        int cnt = 0;
        vector<int> freq(m,0);
        vector<bool> isPrime = seive();
        for(int r = 0;r < n;r++){
            cnt = addfactors(nums[r],cnt,freq,isPrime);
            while(cnt > k){
                cnt = removefactors(nums[l],cnt,freq,isPrime);
                l++;
            }
            ans = max(ans,r - l + 1);
        }   
        return ans;
    }
};