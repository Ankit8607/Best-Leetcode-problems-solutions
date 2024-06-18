// https://leetcode.com/problems/most-profit-assigning-work/description/


class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>arr,v;
        for(int i=0;i<profit.size();i++) arr.push_back({difficulty[i],profit[i]});
        sort(arr.begin(),arr.end());
        v.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            if(arr[i].second>v.back().second) v.push_back(arr[i]);
        }
        int ans=0;
        for(int i=0;i<worker.size();i++){
            auto it=upper_bound(v.begin(),v.end(),make_pair(worker[i],1000000));
            if(it!=v.begin()){
                it--;
                ans+=it->second;
            }
        }
        return ans;
    }
};
