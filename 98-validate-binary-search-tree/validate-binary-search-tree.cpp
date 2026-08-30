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
    bool Bst(TreeNode* root , long long minVal , long long maxVal){
        if(root==NULL) return true ;
        if(root->val <= minVal || root->val >= maxVal) return false ;
        return Bst(root->left , minVal , root->val) && Bst(root->right , root->val , maxVal);
    }
    bool isValidBST(TreeNode* root) {
        // if(root==NULL) return true ;
        // if(root->left != nullptr) {
        //     if(root->left->val >= root->val) return false ;
        //     isValidBST(root->left);
        // }
        // if(root->right != nullptr){
        //     if(root->right->val <= root->val) return false ;
        //     isValidBST(root->right);
        // }
        // return true ;
        return Bst(root ,LLONG_MIN, LLONG_MAX);
    }
};