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
    void traversal(TreeNode* root , vector<int>&val){
        if(root==NULL) return  ;
        traversal(root->left , val);
        val.push_back(root->val);
        traversal(root->right , val);
    }
    bool findTarget(TreeNode* root, int k) {
       vector<int>val ;
       traversal(root , val);
       int n = val.size();
       int cnt = 0 ;
       for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(val[i]+val[j]==k) return true ;
        }
       }
       return false ;


    }
};