// https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/

class Solution {
public:
    int cnt=0;
    int vis[1010][1010];
    set<pair<int,pair<int,int>>>st;
    void rec(vector<vector<int>>& grid,int q){
        while(!st.empty() and (*st.begin()).first<q){
            cnt++;
            int val=(*st.begin()).first;
            int i=(*st.begin()).second.first;
            int j=(*st.begin()).second.second;
            st.erase(st.begin());
            vis[i][j]=1;
            if(i+1<grid.size() and !vis[i+1][j]) st.insert({grid[i+1][j],{i+1,j}});
            if(i-1>=0 and !vis[i-1][j]) st.insert({grid[i-1][j],{i-1,j}});
            if(j+1<grid[0].size() and !vis[i][j+1]) st.insert({grid[i][j+1],{i,j+1}});
            if(j-1>=0 and !vis[i][j-1]) st.insert({grid[i][j-1],{i,j-1}});
        }
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        memset(vis, 0, sizeof(vis));
        st.clear(); cnt=0;
        int n=queries.size();
        vector<int>ans(n);
        st.insert({grid[0][0],{0,0}});
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({queries[i],i});
        }
        sort(v.begin(),v.end());
        for(auto &i:v){
            rec(grid,i.first);
            ans[i.second]=cnt;
        }
        return ans;
    }
};
