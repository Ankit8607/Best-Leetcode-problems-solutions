// https://leetcode.com/problems/shortest-common-supersequence/

class Solution {
public:

    int rec(int l,int r,string &a,string &b,vector<vector<int>>&dp){
        if(l==a.size() || r==b.size()) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        int ans=0;
        if(a[l]==b[r]) ans=1+rec(l+1,r+1,a,b,dp);
        else ans=max(rec(l,r+1,a,b,dp),rec(l+1,r,a,b,dp));

        return dp[l][r]=ans;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=rec(0,0,str1,str2,dp);
        cout<<ans;
        string res,com;
        int i=0,j=0;
        while(i<n and j<m){
            if(str1[i]==str2[j]){
                res+=str1[i];
                ans--;
                i++;j++;
                continue;
            }
            if(j+1<m and dp[i][j+1]==ans) res+=str2[j], j++;
            else res+=str1[i],i++;
        }
        while(i<n) res+=str1[i++];
        while(j<m) res+=str2[j++];
        return res;
    }
};
