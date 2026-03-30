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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        // postorderTraversal(root->left);
        // postorderTraversal(root->right);
        // ans.push_back(root->val);
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* last = nullptr;
        while(curr || !st.empty()){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }else{
                TreeNode* node = st.top();
                if(node->right && last != node->right){
                    curr = node->right;
                }else{
                    ans.push_back(node->val);
                    last = node;
                    st.pop();
                }
            }

        } 
        return ans;
    }
};