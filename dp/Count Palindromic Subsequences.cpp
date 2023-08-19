// https://leetcode.com/problems/count-palindromic-subsequences/

class Solution {
public:
    int countPalindromes(string s) {
        int n=s.size();
        vector<vector<int>>dp1(n,vector<int>(100,0)),dp2(n,vector<int>(100,0));
        vector<int>cnt(10,0);
        cnt[s[0]-'0']=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<100;j++) dp1[i][j]=dp1[i-1][j];
            for(int j=0;j<10;j++) dp1[i][j*10+(s[i]-'0')]+=cnt[j];
            cnt[s[i]-'0']++;
        }
        cnt.clear();
        cnt.resize(10,0);
        cnt[s[n-1]-'0']=1;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<100;j++) dp2[i][j]=dp2[i+1][j];
            for(int j=0;j<10;j++) dp2[i][(s[i]-'0')*10+j]+=cnt[j];
            cnt[s[i]-'0']++;
        }
        int ans=0,mod=1e9+7;
        for(int i=2;i<n-2;i++){
            for(int j=0;j<100;j++){
                ans+=(1LL*dp1[i-1][j]*dp2[i+1][((j%10)*10)+j/10])%mod;
                ans%=mod;
            }
        }
        return ans;
    }
};
