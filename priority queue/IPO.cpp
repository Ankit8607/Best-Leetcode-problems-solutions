// https://leetcode.com/problems/ipo/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        int n=profits.size();
        for(int i=0;i<n;i++) v.push_back({capital[i],profits[i]});
        sort(v.begin(),v.end());
        priority_queue<int>pq;
        int ans=w,i=0;
        while(k--){
            while(i<n and v[i].first<=w){
                pq.push(v[i].second);
                // w+=v[i].second;
                i++;
            }
            if(pq.empty()) break;
            int t=pq.top(); pq.pop();
            w+=t;
        }
        return w;
    }
};
