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
    TreeNode* make(vector<int>& preorder , int start , int end){
        if(start > end ) return NULL ;
        TreeNode* root = new TreeNode(preorder[start]);
        if(start == end ) return root ;
        int leftCount = start+1 ;
        while(leftCount <= end && preorder[leftCount] < root->val) leftCount++ ;
        root->left = make(preorder , start+1 , leftCount-1);
        root->right = make(preorder , leftCount , end);
        return root ;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return make(preorder , 0 , preorder.size()-1);
    }
};