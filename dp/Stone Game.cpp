// https://leetcode.com/problems/stone-game/description/

class Solution {
public:

    int rec(int l,int r,vector<int>& piles,vector<vector<int> > &dp){
        if(l>r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        int ans=max(piles[l]-rec(l+1,r,piles,dp),piles[r]-rec(l,r-1,piles,dp));

        return dp[l][r]=ans;
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int> >dp(n,vector<int>(n,-1));
        return rec(0,n-1,piles,dp)>=0;
    }
};
