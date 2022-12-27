// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

class Solution {
public:
    int ans=0;
    void dfs(int node,int par,set<pair<int,int>>&st,vector<int> *g,int n){
        for(auto &i:g[node]){
            if(i!=par){
                if(st.find({i,node})==st.end()) ans++;
                dfs(i,node,st,g,n);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        set<pair<int,int>>st;
        vector<int>g[n];
        for(auto &i:connections){
            st.insert({i[0],i[1]});
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        dfs(0,-1,st,g,n);
        return ans;
    }
};
