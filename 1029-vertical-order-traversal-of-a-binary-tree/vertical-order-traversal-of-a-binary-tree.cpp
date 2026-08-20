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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , map<int , multiset<int>>>nodes ;
        queue<pair<TreeNode* , pair<int , int>>>todo ;
        todo.push({root ,{0,0}});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first ;
            int ver_idx = p.second.first ;
            int level = p.second . second ;
            nodes[ver_idx][level].insert(node->val);
            if(node->left!=NULL) todo.push({node->left ,{ver_idx-1 , level+1}});
            if(node->right!=NULL) todo.push({node->right ,{ver_idx+1 , level+1}});
        }
        vector<vector<int>> vertical ;
        for(auto p : nodes){
            vector<int>temp ;
            for(auto q : p.second){
                temp.insert(temp.end() , q.second.begin() , q.second.end());
            }
            vertical.push_back(temp);
        }
        return vertical ;
    }
};