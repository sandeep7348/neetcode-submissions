class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int r=height.size()-1;
        int maxArea=0;
        while(i<r)
        {
            int area=min(height[i],height[r])*(r-i);

            maxArea=max(area,maxArea);
            if(height[i]<height[r])
            {
                i++;
            }
            else{
                r--;
            }

        }
        return maxArea;

    }
};