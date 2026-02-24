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
    
    int dfs(TreeNode*root,int num)
    {
        if(root==nullptr)
        {
            return 0;
        }
        num=num*2+root->val;
        if(root->right==nullptr&&root->left==nullptr)
        {
            return num;
        }
        return dfs(root->left,num)+dfs(root->right,num);;
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,0);
    }
};