#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int left = 0,right = 0,sum1 = 0,sum2 = 0;
        for(int i = 0;i < n / 2;i++){
            left += num[i] == '?';
            sum1 += (num[i] - '0') * (num[i] != '?');
        }
        for(int i = n / 2;i < n;i++){
            right += num[i] == '?';
            sum2 += (num[i] - '0') * (num[i] != '?');
        }
        if(left + right == 0){
            return sum1 != sum2;
        }
        if((left + right) % 2){
            return true;
        }
        if(sum1 == sum2){
            return left != right;
        }
        bool check = (sum1 > sum2 && left >= right) || (sum1 < sum2 && left <= right);
        if(check){
            return true;
        }
        if(abs(left - right) % 2){
            return true;
        }
        cout << left << " " << right << " ";
        cout << sum1 << " " << sum2 << " ";
        cout << abs(sum1 - sum2) << " ";
        return !((abs(sum1 - sum2) % 9 == 0)
            && (9 * (abs(left - right) / 2) == abs(sum1 - sum2)));
    }
};