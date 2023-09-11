// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/?envType=daily-question&envId=2023-09-11

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        vector<int>g[n+1];
        for(int i=0;i<n;i++) g[groupSizes[i]].push_back(i);
        vector<vector<int>>ans;
        for(int i=1;i<=n;i++){
            int it=0;
            while(it<g[i].size()){
                vector<int>res;
                for(int j=0;j<i;j++) res.push_back(g[i][it++]);
                ans.push_back(res);
            }
        }
        return ans;
    }
};
