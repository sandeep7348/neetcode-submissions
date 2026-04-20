class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int ans=INT_MAX;
        while(start<=end)
        {
            if(nums[start]<nums[end])
            {
                ans=min(ans,nums[start]);
            }
            
            int mid=start+(end-start)/2;
            ans=min(ans,nums[mid]);
            if(nums[start]<=nums[mid])
            {
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};