// https://leetcode.com/problems/sum-of-distances-in-tree/description/?envType=daily-question&envId=2024-04-28

class Solution {
public:
    int N;
    int dfs(int node,int par, vector<int>&dp,vector<vector<int>>&g,vector<int>&subtree){
        subtree[node]=1;
        for(auto i:g[node]){
            if(i!=par){
                int t=dfs(i,node,dp,g,subtree);
                subtree[node]+=t;
                dp[node]+=dp[i]+t;
            }
        }
        return subtree[node];
    }

    void dfs2(int node,int par, vector<int>&dp,vector<vector<int>>&g,vector<int>&subtree){
        for(auto i:g[node]){
            if(i!=par)
                dp[i]=dp[node]-subtree[i]+(N-subtree[i]),
                dfs2(i,node,dp,g,subtree);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N=n;
        vector<int>dp(n,0),subtree(n,0);
        vector<vector<int>>g(n);
        for(auto i:edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        dfs(0,-1,dp,g,subtree);
        dfs2(0,-1,dp,g,subtree);
        return dp;
    }
};
