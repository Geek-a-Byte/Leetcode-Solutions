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
    vector<int>arr;
    void inOrder(TreeNode* node)
    {
        if (node == NULL)
            return;
    
        inOrder(node->left);
        arr.push_back(node->val);
        inOrder(node->right);
    }

    bool twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        {
            int baki = target-nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]==baki)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        inOrder(root);
        return twoSum(arr, k);
    }
};