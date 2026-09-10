/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    vector<int> solve(TreeNode* root){
        if(!root){
            return {0,0};
        }

        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);

        int sum = left[0] + right[0] + root->val;
        int n = left[1] + right[1] + 1;

        int avg =  sum / n;
        res += avg == root->val;

        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return res;
    }
};