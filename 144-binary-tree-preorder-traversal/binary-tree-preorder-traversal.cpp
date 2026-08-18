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
class Solution {   // root left right
public:
    void display(TreeNode* root , vector<int>&preorder){
        if(root==NULL) return ;
        preorder.push_back(root->val);
        display(root->left, preorder);
        display(root->right , preorder);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder ;
        display(root , preorder);
        return preorder ;
        // stack<TreeNode*>st ;
        // if(root!=NULL) st.push(root);
        // while(st.size()>0){
        //     TreeNode* temp = st.top();
        //     st.pop();
        //     preorder.push_back(temp->val);
        //     if(temp->right != NULL) st.push(temp->right);
        //     if(temp->left != NULL) st.push(temp->left);
        // }
        // return preorder ;
        
    }
};