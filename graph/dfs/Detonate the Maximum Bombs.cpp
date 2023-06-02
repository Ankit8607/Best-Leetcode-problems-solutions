// https://leetcode.com/problems/detonate-the-maximum-bombs/

int rec(int node, vector<int>&vis, vector<vector<int>>&g){
    if(vis[node]) return 0;
    int ans=1;
    vis[node]=1;
    for(auto &i:g[node])  {
        ans+=rec(i,vis,g);
    }
    return ans;
}

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans=0,n=bombs.size();
        vector<vector<int>>g(n);
        for(int i=0;i<n;i++){
            int r=bombs[i][2],x=bombs[i][0],y=bombs[i][1];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x2=bombs[j][0],y2=bombs[j][1];
                if(1LL*(x2-x)*(x2-x)+1LL*(y2-y)*(y2-y)<=1LL*r*r) g[i].push_back(j);
            }
        }
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            ans=max(ans,rec(i,vis,g));
        }
        return ans;
    }
};
