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
    int findSecondMinimumValue(TreeNode* root) {
       int mn = INT_MAX ;
       int sec_mn = -1 ;
       queue<TreeNode*>q ;
       q.push(root);
       while(!q.empty()){
        int size = q.size();
        for(int i=0 ; i<size ; i++){
            TreeNode* node = q.front();
            q.pop();
            mn = min(node->val , mn);
            if(mn != node->val){
                if(sec_mn==-1) sec_mn = node->val ;
                sec_mn = min(node->val , sec_mn);
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
       }
       return sec_mn ;
    }
};