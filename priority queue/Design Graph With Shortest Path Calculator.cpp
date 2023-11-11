// https://leetcode.com/problems/design-graph-with-shortest-path-calculator/description/?envType=daily-question&envId=2023-11-11

class Graph {
public:
    int N;
    vector<vector<pair<int,int>>>g;
    Graph(int n, vector<vector<int>>& edges) {
        N=n;
        g.resize(n);
        for(auto i:edges){
            g[i[0]].push_back({i[1],i[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,node1});
        vector<int>vis(N,0);
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            if(node==node2) return wt;
            if(vis[node]) continue;
            vis[node]=1;
            for(auto i:g[node]){
                if(vis[i.first]) continue;
                pq.push({wt+i.second,i.first});
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
