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
    // int level(TreeNode* root){
    //     if(root==NULL) return 0 ;
    //     return 1+max(level(root->left) , level(root->right));
    // }
    // void rightBoundary(TreeNode* root , vector<int>&view){
    //     if(root==NULL) return ;
    //     TreeNode* temp = root ;
    //     view.push_back(temp->val);
    //     if(root->right!=NULL) rightBoundary(temp->right , view);
    //     else rightBoundary(temp->left , view) ;
    // }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>view ;
        if(root==NULL) return view ;
        queue<TreeNode*>q ;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0 ; i<n ; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(i==n-1) view.push_back(temp->val);
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
        }
        return view ;
    }
};