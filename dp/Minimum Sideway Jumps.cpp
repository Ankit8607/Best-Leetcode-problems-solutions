// https://leetcode.com/problems/minimum-sideway-jumps/

class Solution {
public:
    int dp[500001][4];
    int rec(int level,int path,vector<int>& arr){
        if(level==(arr.size()-1)) return 0;
        if(arr[level]==path) return 1e9;

        if(dp[level][path]!=-1) return dp[level][path];

        int ans=rec(level+1,path,arr);
        for(int i=1;i<4;i++){
            if(path==i) continue;
            if(arr[level]==i) continue;
            ans=min(ans,rec(level+1,i,arr)+1);
   	    }

        return dp[level][path]=ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        memset(dp,-1,sizeof(dp));
        return rec(0,2,obstacles);
    }
};
