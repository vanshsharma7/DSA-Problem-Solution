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
    void inorder(TreeNode* root,vector<int>& num){
        if(root==NULL)
        return ;

        inorder(root->left,num);
        num.push_back(root->val);
        inorder(root->right,num);
    }

    TreeNode* buildTree(int s,int e,vector<int> num){
        if(s>e)
        return NULL;

        int mid=(s+e)/2;

        TreeNode* root=new TreeNode(num[mid]);
        root->left=buildTree(s,mid-1,num);
        root->right=buildTree(mid+1,e,num);

        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL)
        return NULL;

        vector<int> num;
        inorder(root,num);
        int n=num.size()-1;
        return buildTree(0,n,num);    
    }
};