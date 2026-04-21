class Solution {
public:
   int calculateDistance(int a,int b)
   {
     return a*a+b*b;
   }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<points.size();i++)
        {
            int distance=calculateDistance(points[i][0],points[i][1]);
            if(pq.size()<k)
            {
                pq.push({distance,{points[i][0],points[i][1]}});
            }
            else{
                pair<int,pair<int,int>> rs;
                rs=pq.top();
                
                if(rs.first>distance)
                {
                    pq.pop();
                    pq.push({distance,{points[i][0],points[i][1]}});
                }

            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            vector<int> midAns;
            pair<int,pair<int,int>> rq=pq.top();
            pq.pop();
            midAns.push_back(rq.second.first);
            midAns.push_back(rq.second.second);
            ans.push_back(midAns);
        }
        return ans;
    }
};