// https://leetcode.com/problems/minimize-deviation-in-array/description/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int x, y;
        int mn=INT_MAX;
        for (int i:nums){
            if (i&1) i*=2;
            pq.push(i);
            if (i<mn) mn=i;
        }
        int res=INT_MAX;
        while (true){
            x=pq.top();
            pq.pop();
            res=min(res, x-mn);
            if (x&1) break;
            x/=2;
            pq.push(x);
            if (x<mn) mn=x;
        }
        return res;
    }
};
