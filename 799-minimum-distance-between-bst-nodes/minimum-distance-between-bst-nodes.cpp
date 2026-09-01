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
    vector<int>inorder ;
    void traversal(TreeNode* root){
        if(root==NULL) return ;
        traversal(root->left);
        inorder.push_back(root->val);
        traversal(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        if(root==NULL) return 0 ;
        traversal(root);
        int cnt = INT_MAX ;
        for(int i=1 ; i<inorder.size() ; i++){
            cnt = min(cnt , inorder[i]-inorder[i-1]);
        }
        return cnt ;
    }
};