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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* insert = new TreeNode(val);
            return insert ;
        }
        if(root->val < val){//right
            if(root->right == nullptr){
                TreeNode* insert = new TreeNode(val);
                root->right = insert ;
                return root ;
            }
            insertIntoBST(root->right , val) ;
        }else{
            if(root->left == nullptr){
                TreeNode* insert = new TreeNode(val);
                root->left = insert ;
                return root ;
            }
            insertIntoBST(root->left , val) ;
        }
        return root ;
    }
};