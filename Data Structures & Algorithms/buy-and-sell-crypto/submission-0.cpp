class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minAns=INT_MAX;
        int ans=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            minAns=min(minAns,prices[i]);
            ans=max(ans,prices[i]-minAns);
        }
        return ans;
    }
};