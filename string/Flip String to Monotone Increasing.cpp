// https://leetcode.com/problems/flip-string-to-monotone-increasing/description/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        int one[n],zero[n+1];      
        one[0]=s[0]-'0';
        for(int i=1;i<n;i++) one[i]=one[i-1]+(s[i]-'0');
        zero[n]=0;
        for(int i=n-1;i>=0;i--) zero[i]=zero[i+1]+1-(s[i]-'0');
        int ans=zero[0];
        for(int i=0;i<n;i++) ans=min(ans,one[i]+zero[i+1]);
        return ans;
    }
};
