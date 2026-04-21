class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto p:stones)
        {
            pq.push(p);
        }
        while(pq.size()>1)
        {
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            if(first-second>0)
            pq.push(first-second);
        }
        return pq.size()==0?0:pq.top();
    }
};