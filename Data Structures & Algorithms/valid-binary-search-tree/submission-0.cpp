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
    bool isValid(TreeNode* root,long minVal, long maxVal){
        if(!root) return true;
        if(root->val<=minVal || root->val>=maxVal) return false;
        bool right = isValid(root->right,root->val,maxVal);
        bool left = isValid(root->left,minVal,root->val);
        return left && right;
    }
    bool isValidBST(TreeNode* root){
        return isValid(root,LONG_MIN,LONG_MAX);
    }
};
