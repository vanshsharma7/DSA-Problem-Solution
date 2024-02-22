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
    void getElement(TreeNode* root,vector<int> &num){
        if(root==NULL)
        return ;
        getElement(root->left,num);
        num.push_back(root->val);
        getElement(root->right,num);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> num;
        getElement(root1,num);
        getElement(root2,num);
        sort(num.begin(),num.end());
        return num;
    }
};