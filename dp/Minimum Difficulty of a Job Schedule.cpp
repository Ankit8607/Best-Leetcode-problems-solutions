// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

class Solution {
public:
    int dp[301][11];

    int rec(int level,int d,vector<int>&arr){
        if(level==arr.size()) return 0;
        if(d==0) return 1e9;

        if(dp[level][d]!=-1) return dp[level][d];

        int mx=-1,ans=1e9;
        for(int i=level;i<=(int)arr.size()-d;i++){
            mx=max(mx,arr[i]);
            ans=min(ans,mx+rec(i+1,d-1,arr));
        }

        return dp[level][d]=ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n) return -1;
        memset(dp,-1,sizeof(dp));
        return rec(0,d,jobDifficulty);
    }
};
