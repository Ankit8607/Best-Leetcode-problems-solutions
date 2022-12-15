// https://leetcode.com/problems/count-number-of-ways-to-place-houses/description/

class Solution {
public:
    int mod=1e9+7;
    int dp[10010][2];
    int rec(int level,int last,int n){
        if(level==n) return 1;

        if(dp[level][last]!=-1) return dp[level][last];

        int ans=rec(level+1,0,n)%mod;
        if(last==0) ans+=(rec(level+1,1,n)%mod);

        return dp[level][last]=ans%mod;
    }

    int countHousePlacements(int n) {
        memset(dp,-1,sizeof(dp));
        int one=rec(0,0,n)%mod;
        long long int ans=1LL*one*one;
        return ans%mod;
    }
};
