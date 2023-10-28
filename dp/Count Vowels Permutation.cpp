// https://leetcode.com/problems/count-vowels-permutation/description/?envType=daily-question&envId=2023-10-28

class Solution {
public:
    int mod=1e9+7;
    int rec(int n,int last,vector<vector<int>>&dp){
        if(n==0) return 1;

        if(dp[n][last]!=-1) return dp[n][last];

        int ans=0;
        if(last==0) ans+=((rec(n-1,1,dp)+rec(n-1,2,dp))%mod+(rec(n-1,3,dp)+rec(n-1,4,dp))%mod)%mod+rec(n-1,5,dp);
        else if(last==1) ans+=rec(n-1,2,dp);
        else if(last==2) ans+=rec(n-1,1,dp)+rec(n-1,3,dp);
        else if(last==3) ans+=(rec(n-1,1,dp)+rec(n-1,2,dp))%mod+(rec(n-1,4,dp)+rec(n-1,5,dp))%mod;
        else if(last==4) ans+=rec(n-1,3,dp)+rec(n-1,5,dp);
        else ans+=rec(n-1,1,dp);

        return dp[n][last]=ans%mod;
    }

    int countVowelPermutation(int n) {
        vector<vector<int>>dp(n+1,vector<int>(6,-1));
        return rec(n,0,dp);
    }
};
