class Solution {
public:
    vector<vector<int>>ans;
    void permutation(int ind,vector<int> nums) {
        if(ind==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        else
        {
            for(int i=ind;i<nums.size();i++)
            {
                if(i!=ind and nums[i]==nums[ind]) continue;
                swap(nums[i],nums[ind]);
                permutation(ind+1,nums);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        permutation(0,nums);
        return ans;
    }
};