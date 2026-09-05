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
class NodeValue{
public:
    int maxNode , minNode , sum ;
    bool isBST;
    NodeValue(bool isBST , int minNode , int maxNode , int sum){
        this->minNode = minNode ;
        this->maxNode = maxNode ;
        this->sum = sum ;
        this->isBST = isBST;
    }
};
class Solution {
private: 
int globalMaxBSTSum = 0; // Class variable tracks max sum across all valid subtrees

    NodeValue BST(TreeNode* root) {
        if (!root) return NodeValue(true, INT_MAX, INT_MIN, 0);

        auto left = BST(root->left);
        auto right = BST(root->right);

        // Check if BOTH children are valid BSTs AND the boundary conditions hold
        if (left.isBST && right.isBST && left.maxNode < root->val && root->val < right.minNode) {
            int currentSum = left.sum + right.sum + root->val;
            globalMaxBSTSum = max(globalMaxBSTSum, currentSum);
            
            return NodeValue(
                true, 
                min(root->val, left.minNode), 
                max(root->val, right.maxNode), 
                currentSum
            );
        }

        // Not a BST
        return NodeValue(false, INT_MIN, INT_MAX, 0);
    }
public:
    int maxSumBST(TreeNode* root) {
        globalMaxBSTSum = 0;
        BST(root);
        return globalMaxBSTSum;
    }
};