#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long count(vector<int>& coins, long long target) {
        int n = coins.size();
        long long res = 0;

        // Inclusion-exclusion over all subsets
        for (int mask = 1; mask < (1 << n); mask++) {
            long long lcm = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    long long g = gcd(lcm, (long long)coins[i]);

                    // Avoid overflow
                    if (lcm > target / (coins[i] / g)) {
                        valid = false;
                        break;
                    }

                    lcm = lcm / g * coins[i];

                    if (lcm > target) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            long long ways = target / lcm;

            if (bits % 2 == 1)
                res += ways;
            else
                res -= ways;
        }

        return res;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());

        long long l = 1;
        long long r = 1e15;
        long long ans = 1e15;

        while (l <= r) {
            long long mid = l + (r - l) / 2;

            if (count(coins, mid) >= k) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};