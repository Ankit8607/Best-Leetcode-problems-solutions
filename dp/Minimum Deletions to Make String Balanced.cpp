// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int cnta[n+1],cntb[n];
        cntb[0]=0;
        if(s[0]=='b') cntb[0]=1;
        for(int i=1;i<n;i++) cntb[i]=cntb[i-1]+(s[i]=='b');
        cnta[n]=0;
        for(int i=n-1;i>=0;i--) cnta[i]=cnta[i+1]+(s[i]=='a');

        int ans=cnta[0];
        for(int i=0;i<n;i++){
            ans=min(ans,cntb[i]+cnta[i+1]);
        return ans;
    }
};
