class Solution {
public:

    void balance(priority_queue<int> &left,
                 priority_queue<int, vector<int>, greater<int>> &right)
    {
        if(left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        else if(right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    void addNum(int num,
                priority_queue<int> &left,
                priority_queue<int, vector<int>, greater<int>> &right)
    {
        if(left.empty() || num <= left.top())
            left.push(num);
        else
            right.push(num);

        balance(left, right);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        priority_queue<int> left; 
        priority_queue<int, vector<int>, greater<int>> right; 

        for(int x : nums1)
            addNum(x, left, right);

        for(int x : nums2)
            addNum(x, left, right);

        if(left.size() == right.size())
            return (left.top() + right.top()) / 2.0;
        else
            return left.top();
    }
};
