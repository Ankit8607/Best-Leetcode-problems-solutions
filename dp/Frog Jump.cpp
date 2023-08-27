// https://leetcode.com/problems/frog-jump/

class Solution {
public:

    int rec(int level,int last,vector<int>&stones, vector<vector<int>>&dp,unordered_map<int,int>&mp){
        if((level+1)>=stones.size()) return (level+1)==stones.size();

        if(dp[level][last]!=-1) return dp[level][last];

        int ans=0;
        int k=2*stones[level]-stones[last];
        if(mp.count(k)) ans|=rec(mp[k],level,stones,dp,mp);
        if(mp.count(k+1)) ans|=rec(mp[k+1],level,stones,dp,mp);
        if(k-1>stones[level] and mp.count(k-1)) ans|=rec(mp[k-1],level,stones,dp,mp);

        return dp[level][last]=ans;
    }

    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(stones[1]!=1) return 0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[stones[i]]=i;
        return rec(1,0,stones,dp,mp);
    }
};
