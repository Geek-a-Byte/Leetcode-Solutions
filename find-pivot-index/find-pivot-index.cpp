class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 0;
        }
        int ans=-1;
        int left_sum=0;
        int right_sum=0;
        for(int i=1;i<nums.size();i++)
        {
            right_sum+=nums[i];
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            // cout<<left_sum<<" "<<right_sum<<endl;
            if(left_sum==right_sum)
            {
                ans=i;
                return ans;
            }
            left_sum+=nums[i];
            right_sum-=nums[i+1];
            // cout<<left_sum<<" "<<right_sum<<endl;
        }
        if(left_sum==right_sum) return ans=nums.size()-1;
        return ans;
        
    }
};