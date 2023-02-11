// https://leetcode.com/problems/shortest-path-with-alternating-colors/

class Solution {
public:

    void rec(vector<vector<int>>&vis,vector<vector<int>>&ans, vector<vector<int>> &r,vector<vector<int>>&b){
        queue<pair<int,int>>q;
        q.push({0,0}); vis[0][0]=1;
        q.push({0,1}); vis[0][1]=1;
        while(!q.empty()){
            pair<int,int>p=q.front();
            int node=p.first;
            q.pop();
            if(p.second==0){ // last color travelled is red 
                for(auto &i:b[node]){
                    if(!vis[i][1]){
                        ans[i][1]=min(ans[i][1],1+ans[node][0]);
                        q.push({i,1});
                        vis[i][1]=1;
                    }
                }
            }
            else{ // last color travelled is blue
                for(auto &i:r[node]){
                    if(!vis[i][0]){
                        ans[i][0]=min(ans[i][0],1+ans[node][1]);
                        // cout<<"blue"<<i<<" "<<ans[i]<<endl;
                        q.push({i,0});
                        vis[i][0]=1;
                    }
                }
            }
        }
    }   

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>r(n),b(n);
        for(auto &i:redEdges) r[i[0]].push_back(i[1]);
        for(auto &i:blueEdges) b[i[0]].push_back(i[1]);
        vector<vector<int>>vis(n,vector<int>(2,0));
        vector<vector<int>>ans(n,vector<int>(2,1e9));
        ans[0][0]=0;
        ans[0][1]=0;
        vector<int>res(n,-1);
        rec(vis,ans,r,b);
        int t=0;
        for(auto &i:ans){
            if(i[0]!=1e9 || i[1]!=1e9) res[t]=min(i[0],i[1]); t++;
        }
        return res;
    }
};
