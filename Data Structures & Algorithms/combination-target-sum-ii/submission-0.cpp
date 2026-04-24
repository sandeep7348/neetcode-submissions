class Solution {
public:
   void buildHelper(int index,vector<int>& candidates, int target,vector<int> & ans ,vector<vector<int>> & totalCombination)
   {
      
        if(target==0)
        {
            totalCombination.push_back(ans);
            return ;
            
        }
    
    
      for(int i=index ;i<candidates.size();i++)
      {
        if(i> index && candidates[i]==candidates[i-1]) continue;
        if (candidates[i] > target) break;
        if(candidates[i]<=target)
        {
           ans.push_back(candidates[i]);
           buildHelper(i+1,candidates,target-candidates[i],ans,totalCombination);
           ans.pop_back();
        }
      }
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ans;
        vector<vector<int>> totalCombination;
        buildHelper(0, candidates, target, ans, totalCombination);
        return totalCombination;

    }
};
