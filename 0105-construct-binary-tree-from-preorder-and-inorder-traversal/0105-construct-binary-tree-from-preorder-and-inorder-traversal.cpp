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
    int findPos(vector<int> inorder,int element){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element)
            return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int> inorder,vector<int> preorder,int &index,int indexStart,int indexEnd){
        if(index>=inorder.size() || indexStart>indexEnd){
            return NULL;
        }
        
        int element=preorder[index++];
        TreeNode* root=new TreeNode(element);
        int position=findPos(inorder,element);
        
        root->left=solve(inorder,preorder,index,indexStart,position-1);
        root->right=solve(inorder,preorder,index,position+1,indexEnd);
        
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        TreeNode *ans=solve(inorder,preorder,index,0,inorder.size()-1);
        return ans;
    }
};