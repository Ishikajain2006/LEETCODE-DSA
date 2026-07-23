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
    int ans = 0 ;
    int dfs(TreeNode* root){
       if(root == NULL) return INT_MIN ;
        int subtreeMax = max(root->val , max(dfs(root->left), dfs(root->right))) ;
        if(subtreeMax == root->val) ans++ ;
        return subtreeMax ;
    }
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return ans ;
    }
};