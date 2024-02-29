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
private:
    void inorder(TreeNode* root,vector<TreeNode*>& num){
        if(root==NULL)
        return ;

        num.push_back(root);
        inorder(root->left,num);
        inorder(root->right,num);
    }
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
        return ;

        vector<TreeNode*> num;
        inorder(root,num);
        int i;
        for(i=0;i<num.size()-1;i++){
            num[i]->left=NULL;
            num[i]->right=num[i+1];
        }
        num[i]->left=NULL;
        num[i]->right=NULL;
        root=num[i];
    }
};