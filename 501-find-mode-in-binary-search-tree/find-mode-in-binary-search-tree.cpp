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
    vector<int> ans; // ans to return
    TreeNode* prev = NULL; // previousnode's value
    int count = 0; //to store frequency
    int maxCount = 0; // to store the max frequency

    void inorder(TreeNode* root) { // inorder give sorted tree sequence
        if (root == NULL) return; // base case
        inorder(root->left);
        if (prev == NULL)  count = 1; // Process current node
        else if (prev->val == root->val)  count++; // if element is same frequence++
        else  count = 1; // turn to calculate next ele frequency 
        if (count > maxCount) { // to check current frequency is greater or not
            maxCount = count;
            ans.clear(); // empty the vector because we find higher frequency
            ans.push_back(root->val);
        } else if (count == maxCount) {
            ans.push_back(root->val); //if same frequency ele occur then push it 
        }
        prev = root; // to store the previous node
        inorder(root->right); // now similarly traverse through right
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans ;
    }
};