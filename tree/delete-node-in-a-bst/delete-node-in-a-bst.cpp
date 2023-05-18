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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val==key)
        {
            return helper(root);
        }
        TreeNode* curr=root;
        while(curr)
        {
            if(curr->val>key)
            {
                //left e jabe
                if(curr->left!=NULL and curr->left->val==key)
                {
                    curr->left = helper(curr->left);
                }
                else curr=curr->left;
            }
            else
            {
                //right e jabe
                if(curr->right!=NULL and curr->right->val==key)
                {
                    curr->right = helper(curr->right);
                }
                else curr=curr->right;
            }
        }
        return root;
    }
    TreeNode* helper(TreeNode* root)
    {
        if(root->left==NULL)
        {
            return root->right;
        }
        if(root->right==NULL)
        {
            return root->left;
        }
        else
        {
            //see the example at 9.06: https://www.youtube.com/watch?v=kouxiP_H5WE&ab_channel=takeUforward
            //5
            TreeNode* rightChild=root->right; //7
            TreeNode* lastRightonLeft=findLastRight(root->left); //4
            lastRightonLeft->right=rightChild;
            return root->left; //2
        }
    }
    TreeNode* findLastRight(TreeNode* root)
    {
        if(root->right==NULL)
        {
            return root;
        }
        return findLastRight(root->right);
    }
};