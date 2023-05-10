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
    priority_queue<int, vector<int>, greater<int>>tree_to_arr;
    void preOrder(TreeNode* node)
    {
        if (node == NULL)
            return;
        
        tree_to_arr.push(node->val);
        preOrder(node->left);
        preOrder(node->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        preOrder(root);
        int ans=-1;
        while(k>0 and !tree_to_arr.empty())
        {
            ans=tree_to_arr.top();
            tree_to_arr.pop();
            k--;
        }
        return ans;
    }
};