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
    int avg = 0 ;
    pair<int , int> dfs(TreeNode* root){
        if(root==NULL) return {0,0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int count = left.second + right.second + 1 ;
        int sum = left.first + right.first + root->val ;
        int average = sum/count;
        if(average == root->val) avg++ ;
        return { sum , count};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return avg ;
    }
};