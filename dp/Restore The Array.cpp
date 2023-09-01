// https://leetcode.com/problems/restore-the-array/description/?envType=daily-question&envId=2023-09-01

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n=s.size(),mod=1e9+7;
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            long long num=0;
            for(int j=0;(j<10) and (i-j>=0);j++){
                num=num+(s[i-j]-'0')*1LL*pow(10,j);
                if(num>k) break;
                if(s[i-j]!='0' and num <= k and num>0) dp[i]=(dp[i]+(i-j-1>=0 ? dp[i-j-1] : 1))%mod;
            }
        }
        return dp[n-1];
    }
};
