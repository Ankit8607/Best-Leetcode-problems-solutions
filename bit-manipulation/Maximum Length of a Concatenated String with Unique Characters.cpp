// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23

class Solution {
public:

    int rec(int level,vector<bitset<26>>&dp,bitset<26>bs){
        if(level==dp.size()) return bs.count();

        int ans=0;
        if((dp[level]&bs)==0) ans=rec(level+1,dp,bs|dp[level]);
        ans=max(ans,rec(level+1,dp,bs));

        return ans;
    }

    int maxLength(vector<string>& arr) {
        int n=arr.size();
        vector<bitset<26>>dp(n);
        for(int i=0;i<n;i++){
            for(auto j:arr[i]){
                if(dp[i][j-'a']){
                    dp[i]=0;
                    break;
                }
                else dp[i][j-'a']=1;
            }
        }
        bitset<26>bs(0);
        return rec(0,dp,bs);
    }
};
