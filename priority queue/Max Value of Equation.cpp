// https://leetcode.com/problems/max-value-of-equation/description/

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;
        pq.push({points[0][1]-points[0][0],points[0][0]});
        int ans=-1e9;
        for(int i=1;i<points.size();i++){
            while(!pq.empty() and abs(pq.top().second-points[i][0])>k) pq.pop();
            if(!pq.empty()) ans=max(ans,points[i][1]+points[i][0]+pq.top().first);
            pq.push({points[i][1]-points[i][0],points[i][0]});
        }
        
        return ans;
    }
};
