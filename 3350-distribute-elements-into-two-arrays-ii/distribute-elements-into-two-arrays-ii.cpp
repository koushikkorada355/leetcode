#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        ordered_set<pair<int,int>> arr1, arr2;

        vector<int> nums1, nums2;

        nums1.push_back(0);
        nums2.push_back(1);

        arr1.insert({nums[0], 0});
        arr2.insert({nums[1], 1});

        for (int i = 2; i < n; i++) {

            // Number of elements > nums[i]
            int a = arr1.size() -
                    arr1.order_of_key({nums[i] + 1, -1});

            int b = arr2.size() -
                    arr2.order_of_key({nums[i] + 1, -1});

            if (a > b) {
                arr1.insert({nums[i], i});
                nums1.push_back(i);
            }
            else if (a < b) {
                arr2.insert({nums[i], i});
                nums2.push_back(i);
            }
            else if (arr1.size() > arr2.size()) {
                arr2.insert({nums[i], i});
                nums2.push_back(i);
            }
            else {
                arr1.insert({nums[i], i});
                nums1.push_back(i);
            }
        }

        vector<int> res;

        for (int e : nums1)
            res.push_back(nums[e]);

        for (int e : nums2)
            res.push_back(nums[e]);

        return res;
    }
};