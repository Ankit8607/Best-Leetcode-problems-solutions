// https://leetcode.com/problems/number-of-music-playlists/description/

class Solution {
public:
    int mod=1e9+7;

    int rec(int level,int goal, int n,int &tot, int &k,vector<int>& vis,vector<int>& pos,vector<vector<int>>&dp){
        if(goal==level) return n==0;

        if(dp[level][n]!=-1) return dp[level][n];

        int ans=0;
        for(int i=0;i<tot;i++){
            if(level-pos[i]>k){
                int tmp=pos[i];
                pos[i]=level;
                if(vis[i]==0){
                    vis[i]=1;
                    ans+=rec(level+1,goal,n-1,tot,k,vis,pos,dp)%mod;
                    vis[i]=0;
                }
                else ans+=rec(level+1,goal,n,tot,k,vis,pos,dp)%mod;
                ans%=mod;
                pos[i]=tmp;
            }
        }
        return dp[level][n]=ans%mod;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>>dp(goal,vector<int>(n+1,-1));
        vector<int>vis(n,0),pos(n,-k-1);
        return rec(0,goal,n,n,k,vis,pos,dp);
    }
};
