// https://leetcode.com/problems/stone-game-viii/description/

class Solution {
public:
    int rec(int level,vector<int>& stones, int *dp,int *pre){
        if(level==stones.size()-1) return 0;

        if(dp[level]!=-1) return dp[level];

        int ans=-1e9;
        for(int i=level+1;i<stones.size();i++){
            ans=max(ans,pre[i]-rec(i,stones,dp,pre));
        }

        return dp[level]=ans;
    }
    int stoneGameVIII(vector<int>& stones) {
       int n=stones.size();
       int dp[n],pre[n];
       memset(dp,-1,sizeof(dp));
       pre[0]=stones[0];
       for(int i=1;i<n;i++) pre[i]=pre[i-1]+stones[i];
       return rec(0,stones,dp,pre); 
    }
};
