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

    void dfs(TreeNode*root, vector<int> &arr)
    {
        if(root==nullptr)
        return;
        dfs(root->left, arr);
        arr.push_back(root->val);
        dfs(root->right,arr);
    }
    TreeNode* generate(vector<int>&arr, int l,int r)
    {
        if(l>r)
        {
            return NULL;
        }
        int mid=l+(r-l)/2;
        TreeNode* root=new TreeNode(arr[mid]);
        root->left=generate(arr,l,mid-1);
        root->right=generate(arr,mid+1,r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        dfs(root,arr);
        TreeNode* newRoot=generate(arr,0,arr.size()-1);
        return newRoot;
    }
};