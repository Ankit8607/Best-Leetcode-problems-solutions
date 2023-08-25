// https://leetcode.com/problems/interleaving-string/

// class Solution {
// public:

//     int rec(int l,int r,int i,string &a,string &b,string &c,vector<vector<vector<int>>>&dp){
//         if(i==c.size()) return 1;

//         if(dp[l][r][i]!=-1) return dp[l][r][i];

//         int ans=0;
//         if(l<a.size() and a[l]==c[i]) ans|=rec(l+1,r,i+1,a,b,c,dp);
//         if(r<b.size() and b[r]==c[i]) ans|=rec(l,r+1,i+1,a,b,c,dp);

//         return dp[l][r][i]=ans;
//     }

//     bool isInterleave(string s1, string s2, string s3) {
//         if(s1.size()+s2.size()!=s3.size()) return 0;
//         vector<vector<vector<int>>>dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
//         return rec(0,0,0,s1,s2,s3,dp);
//     }
// };

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s3.length() != s1.length() + s2.length())
            return false;
        
        bool table[s1.length()+1][s2.length()+1];
        
        for(int i=0; i<s1.length()+1; i++)
            for(int j=0; j< s2.length()+1; j++){
                if(i==0 && j==0)
                    table[i][j] = true;
                else if(i == 0)
                    table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
                else if(j == 0)
                    table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
                else
                    table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
            }
            
        return table[s1.length()][s2.length()];
    }
};
