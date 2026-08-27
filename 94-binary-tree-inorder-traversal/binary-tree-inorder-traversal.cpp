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
    // void display(TreeNode* root , vector<int>&inorder){
    //     if(root==NULL) return ;
    //     display(root->left , inorder );
    //     inorder.push_back(root->val);
    //     display(root->right , inorder);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder ;
        // display(root , inorder);
        TreeNode* curr = root ;
        while(curr != NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr = curr->right ;
            }
            else{
                TreeNode* prev = curr->left ;
                while(prev->right && prev->right != curr){
                    prev = prev->right ;
                }
                if(prev->right == NULL){
                    prev->right = curr ;
                    curr = curr->left ;
                }else{
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right ;
                }
            }
        }
        return inorder ;
    }
};