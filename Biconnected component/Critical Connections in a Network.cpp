// https://leetcode.com/problems/critical-connections-in-a-network/

/*

There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 

Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.

*/


class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        vector<vector<int>>g(n); // 0 indexed graph
        for(int i=0;i<m;i++){
            int a=connections[i][0],b=connections[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<int> disc(n,-1),low(n,-1),parent(n,-1);
        vector<vector<int>>bridge;

        for(int i=0;i<n;i++){
            if(disc[i]==-1) 
                dfs(i,disc,low,parent,bridge,g);
        }
        return bridge;
    }
    void dfs(int u,vector<int>&disc,vector<int>&low, vector<int> &parent, vector<vector<int>>&bridge,vector<vector<int>>&g){
        static int time=0;
        disc[u]=low[u]=time;
        time++;

        for(int v:g[u]){
            if(disc[v]==-1){ // if v is not visited
                parent[v]=u;
                dfs(v,disc,low,parent,bridge,g);
                low[u]=min(low[u],low[v]);

                if(low[v]>disc[u])
                    bridge.push_back({u,v});
            }

            else if(v!=parent[u]) // Ignore child to parnet edge
                low[u]=min(low[u],disc[v]);
        }
    }
};
