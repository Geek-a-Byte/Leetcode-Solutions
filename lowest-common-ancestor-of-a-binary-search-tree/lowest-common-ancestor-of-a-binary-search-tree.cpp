/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Function should return all the ancestor of the target node
    bool getPath(TreeNode* root, int x, vector<int>& arr)
    {
        if(root==NULL)
        {
            return false;
        }
        
        arr.push_back(root->val);
        
        if(root->val==x)
        {
            return true;
        }
        
        if(getPath(root->left, x, arr) or getPath(root->right, x, arr))
        {
            return true;
        }
        
        arr.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int>v;
        int ans=getPath(root, p->val, v);
        // v.pop_back();
        // sort(v.begin(),v.end());

        vector<int>v2;
        ans=getPath(root, q->val, v2);
        // v2.pop_back();
        // sort(v2.begin(),v2.end());
        
        for(auto i:v)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i:v2)
        {
            cout<<i<<" ";
        }
        
        int n=v2.size();
        int m=v.size();
        int f=0;
        TreeNode* ansNode=NULL;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i]==v2[j])
                {
                   ansNode=new TreeNode(v2[j]);
                   break;
                }
            }
        }
        // TreeNode* ansNode=new TreeNode(v2[i-1]);
        return ansNode;
    }
};