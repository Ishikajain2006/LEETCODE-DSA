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
    void check(TreeNode* lroot , TreeNode* rroot , bool &flag){
        if(flag==false) return ;
        if(lroot == NULL && rroot == NULL){
            flag = true ;
            return ;
        }
        if(lroot == NULL || rroot == NULL){
            flag = false ;
            return ;
        }
        if(lroot->val != rroot->val){
            flag = false ;
            return ;
        }
        check(lroot->left , rroot->right , flag);
        check(lroot->right , rroot->left , flag );
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true ;
        if(root->left == NULL && root->right==NULL) return true ;
        if(root->left == NULL || root->right == NULL) return false ;
        bool flag = true ;
        check(root->left , root->right , flag);
        return flag ;
    }
};