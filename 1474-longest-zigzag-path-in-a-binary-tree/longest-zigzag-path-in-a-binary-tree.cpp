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

      int l = 1 + left[1];
      int r = 1 + right[0];
      res = max({res,l,r});
      return {l,r};
    }
    int longestZigZag(TreeNode* root) {
        solve(root);
        return res - 1;
    }
};