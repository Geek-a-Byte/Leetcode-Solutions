class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>ans(2);
        for(int i=0;i<nums.size();i++)
        {
            int f=0;
            int baki = target-nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]==baki)
                {
                    f=1;
                    ans[0]=i;
                    ans[1]=j;
                    break;
                }
            }
            if(f) break;
        }
        return ans;
    }
};