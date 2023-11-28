// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description/?envType=daily-question&envId=2023-11-28

class Solution {
public:
    int mod=1e9+7;
    int rec(int level,int cnt, string &s, vector<vector<int>>&dp){
        if(level==s.size()){
            if(cnt==2) return 1;
            return 0;
        }

        if(dp[level][cnt]!=-1) return dp[level][cnt];

        int ans=0;
        if(cnt==2){
            if(s[level]=='S') ans=rec(level+1,1,s,dp);
            else ans=rec(level+1,2,s,dp)+rec(level+1,0,s,dp);
        }
        else ans=rec(level+1,cnt+(s[level]=='S'),s,dp);

        return dp[level][cnt]=ans%mod;
    }

    int numberOfWays(string corridor) {
        int cnt=0,n=corridor.size();
        for(auto i:corridor) if(i=='S') cnt++;
        if(cnt%2) return 0;

        vector<vector<int>>dp(n,vector<int>(3,-1));
        return rec(0,0,corridor,dp);
    }
};
