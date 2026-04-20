class Solution {
  public:
    vector<int> twoSum(vector<int>& arr, int target) {
      unordered_map<int,int> m;
      vector<int> ans;
      for(int i=0;i<arr.size();i++)
      {   int rem=target-arr[i];
          if(m.find(rem)!=m.end())
          {
              ans.push_back(m[rem]+1);
              ans.push_back(i+1);
              return ans;
          }
          m[arr[i]]=i;
      }
      ans.push_back(-1);
      ans.push_back(-1);
      return ans;
      
    }
};