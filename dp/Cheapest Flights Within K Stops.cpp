// https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution {
public:
    int dp[101][101];

    int rec(int src,int dst,int k,vector<vector<pair<int,int>>>&g){
        if(k<0) return 1e9;

        if(src==dst) return 0;
 
        if(dp[src][k]!=-1) return dp[src][k];

        int ans=1e9;
        for(auto &i:g[src]){
            ans=min(ans,i.second+rec(i.first,dst,k-1,g));
        }

        return dp[src][k]=ans;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);
        memset(dp,-1,sizeof(dp));
        for(auto &i:flights) g[i[0]].push_back({i[1],i[2]});
        int ans=rec(src,dst,k+1,g);
        return ans>=1e9?-1:ans;
    }
};
