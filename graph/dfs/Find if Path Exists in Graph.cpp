// https://leetcode.com/problems/find-if-path-exists-in-graph/description/?envType=daily-question&envId=2024-04-21

class Solution {
public:

    void rec(int node,int end,vector<vector<int>>&g,vector<int>&vis){
        vis[node]=1;
        for(auto i:g[node]){
            if(!vis[i])
                rec(i,end,g,vis);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>g(n);
        for(auto i:edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        rec(source,destination,g,vis);
        return vis[destination];
    }
};



// In python

// class Solution:
//     def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
//         def rec(node,g,vis):
//             vis[node]=1
//             for i in g[node]:
//                 if not vis[i]:
//                     rec(i,g,vis)
//         g=[[] for _ in range(n)]
//         for i in edges:
//             g[i[0]].append(i[1])
//             g[i[1]].append(i[0])
//         vis=[0 for i in range(n)]
//         rec(source,g,vis)
//         return vis[destination]


// In javascript

// /**
//  * @param {number} n
//  * @param {number[][]} edges
//  * @param {number} source
//  * @param {number} destination
//  * @return {boolean}
//  */
// var validPath = function(n, edges, source, destination) {
//     let g=new Array(n);
//     for(let i=0;i<n;i++) g[i]=[];
//     for(let i of edges){
//         g[i[0]].push(i[1]);
//         g[i[1]].push(i[0]);
//     }
//     let vis=new Array(n).fill(0);
//     rec(source,g,vis);
//     return vis[destination];
// };

// var rec=(node,g,vis)=>{
//     vis[node]=1;
//     for(let i of g[node]){
//         if(!vis[i])
//             rec(i,g,vis);
//     }
// }
