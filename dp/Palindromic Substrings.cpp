// https://leetcode.com/problems/palindromic-substrings/description/

class Solution {
public:

    int res=0;
    int rec(int l,int r,string &s, vector<vector<int>>&dp){
        if(r<l) return 1;

        if(dp[l][r]!=-1) return dp[l][r];

        int ans=0;
        if(s[l]==s[r] and rec(l+1,r-1,s,dp)) ans=1,res++;
        rec(l+1,r,s,dp);
        rec(l,r-1,s,dp);

        return dp[l][r]=ans;
    }

    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        rec(0,n-1,s,dp);
        return res;
    }
};
