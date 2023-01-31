// https://leetcode.com/problems/best-team-with-no-conflicts/

class Solution      {
public:
    vector<pair<int,int>>v;

    int rec(int level,int last,vector<pair<int,int>>&v,int dp[][1001]){
        if(level==v.size()) return 0;

        if(dp[level][last]!=-1) return dp[level][last];

        int ans=rec(level+1,last,v,dp);
        if(v[level].second>=last) ans=max(v[level].first+rec(level+1,v[level].second,v,dp),ans);

        return dp[level][last]=ans;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        for(int i=0;i<n;i++) v.push_back({scores[i],ages[i]});
        sort(v.begin(),v.end());
        int dp[n][1001];
        memset(dp,-1,sizeof(dp));
        return rec(0,0,v,dp);
    }
};
