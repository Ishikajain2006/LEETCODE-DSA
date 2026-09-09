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
    TreeNode* find(TreeNode* root , int start){
        if(root==NULL) return NULL ;
        if(root->val==start) return root ;
        TreeNode* leftSearch = find(root->left, start);
        if (leftSearch != NULL) return leftSearch;
        return find(root->right, start);
    }
    void tracker(TreeNode* root ,  unordered_map<TreeNode* , TreeNode*>& parent ){
        if (root == NULL) return;
        if(root->left) {
          parent[root->left] = root ;
          tracker(root->left , parent);
        }
        if(root->right) {
          parent[root->right] = root ;
          tracker(root->right , parent);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* , TreeNode*> parent ;
        tracker(root , parent );
        TreeNode* start_node = find(root , start);
        unordered_map<TreeNode* , bool> visited ;
        queue<TreeNode*>q ;
        q.push(start_node);
        int time = 0 ;
        visited[start_node]=true ;
        while(!q.empty()){
            int size = q.size();
            bool flag = false ;
            for(int i=0 ; i<size ; i++){
                TreeNode* Node = q.front();
                q.pop();
                if(Node->left!=NULL  && visited[Node->left]==false){
                    flag = true;
                    q.push(Node->left) ;
                    visited[Node->left]=true ;
                }
                if(Node->right!=NULL  && visited[Node->right]==false){
                    flag = true;
                    q.push(Node->right) ;
                    visited[Node->right]=true ;
                }
                if(parent.find(Node) != parent.end() && visited[parent[Node]]==false){
                    flag = true;
                    q.push(parent[Node]) ;
                    visited[parent[Node]]=true ;
                }
            }
            if(flag==true) time++ ;
        }
        return time ;
    }
};