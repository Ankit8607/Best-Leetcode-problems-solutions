// https://leetcode.com/problems/queue-reconstruction-by-height/

class Solution {
public:

    static bool comp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        vector<pair<int,int>>v;
        for(auto &i:people) v.push_back({i[0],i[1]});
        sort(v.begin(),v.end(),comp);
        vector<vector<int>>ans(n,vector<int>(2,-1));
        for(auto &i:v){
            int tar=i.second;
            for(int j=0;j<n;j++){
                if(!tar and ans[j][1]==-1){
                    ans[j][0]=i.first;
                    ans[j][1]=i.second;
                    break;
                }
                if(ans[j][1]==-1) tar--;
            }
        }
        return ans;
    }
};
