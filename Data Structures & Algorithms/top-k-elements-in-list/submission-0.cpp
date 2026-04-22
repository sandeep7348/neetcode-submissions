class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        
        
        for(auto num : nums) {
            m[num]++;
        }

        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto x : m) {
            if(pq.size() < k) {
                pq.push({x.second, x.first});
            } 
            else if(pq.top().first < x.second) {
                pq.pop();
                pq.push({x.second, x.first});
            }
        }

        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};