class Solution {
public:
   void buildHelper(int index,int target,vector<int> &nums,vector<int> & ans,vector<vector<int>> &totalCombination)
   {
       if(index==nums.size())
       {
          if(target==0)
          {
            totalCombination.push_back(ans);
            
            
          }
          return ;

       }
       if(nums[index]<=target)
       {
        ans.push_back(nums[index]);
        buildHelper(index,target-nums[index],nums,ans,totalCombination);
        ans.pop_back();
       }
       buildHelper(index+1,target,nums,ans,totalCombination);
   }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<vector<int>> totalCombination;
        buildHelper(0,target,nums,ans,totalCombination);
        return totalCombination;

    }
};
