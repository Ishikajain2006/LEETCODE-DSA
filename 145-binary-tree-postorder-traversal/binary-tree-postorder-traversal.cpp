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
    void display(TreeNode* root , vector<int>&postorder){
        if(root==NULL) return ;
        display(root->left , postorder);
        display(root->right , postorder);
        postorder.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder ;
        // display(root , postorder);
        stack<TreeNode*>st ;
        if(root == nullptr) return postorder;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            postorder.push_back(node->val);
            if(node->left != NULL) st.push(node->left);
            if(node->right != NULL) st.push(node->right);
        }
        reverse(postorder.begin() , postorder.end());
        return postorder ;
    }
};