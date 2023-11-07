// https://leetcode.com/problems/student-attendance-record-ii/description/

class Solution {
public:
    int dp[100010][3][2],mod=1e9+7;

    int rec(int level,int late, int absent){
        if(absent==2) return 0;
        if(level==0) return 1;

        if(dp[level][late][absent]!=-1) return dp[level][late][absent];

        int ans=0;
        if(late==2)ans=rec(level-1,0,absent)+rec(level-1,0,absent+1);
        else ans=rec(level-1,late+1,absent)+(rec(level-1,0,absent)+rec(level-1,0,absent+1))%mod;

        return dp[level][late][absent]=ans%mod;
    }

    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(n,0,0);
    }
};
