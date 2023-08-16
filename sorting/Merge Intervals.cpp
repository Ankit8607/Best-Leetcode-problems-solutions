// https://leetcode.com/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int st=-1,end=-1;
        vector<vector<int>>ans;
        for(auto i: intervals){
            if(i[0]<=end){
                end=max(end,i[1]);
                ans.back()[1]=end;
            }
            else{
                ans.push_back({i[0],i[1]});
                end=i[1];
            }
        }
        return ans;
    }
};
