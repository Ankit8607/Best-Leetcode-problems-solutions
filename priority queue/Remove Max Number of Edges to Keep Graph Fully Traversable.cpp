// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/?envType=daily-question&envId=2024-06-30

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>g(n+1);
        for(auto i:edges){
            g[i[1]].push_back({i[0],i[2]});
            g[i[2]].push_back({i[0],i[1]});
        }
        priority_queue<pair<int,int>>pq;
        pq.push({3,1});

        vector<int>vis(n+1,0);
        int ans=0,mytype=1,cnt=0;

        while(!pq.empty()){
            int node = pq.top().second;
            int t = pq.top().first;
            pq.pop();
            if(vis[node]) {
                ans++; 
                if(t==3) cnt++;
                continue;
            }
            vis[node]=1;
            for(auto child:g[node]){
                int type = child.first;
                if(type==mytype || type==3){
                    if(vis[child.second]==0) pq.push({child.first,child.second});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==0) return -1;
        }

        mytype=2;
        vis.assign(n+1,0);
        pq.push({3,1});
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            if(vis[node]) {
                ans++; 
                continue;
            }
            vis[node]=1;
            for(auto child:g[node]){
                int type = child.first;
                if(type==mytype || type==3){
                    if(vis[child.second]==0) pq.push({child.first,child.second});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==0) return -1;
        }
        return ans-cnt;
    }
};
