// https://leetcode.com/problems/maximum-deletions-on-a-string/

class Solution {
public:
    long long mod=999999937,p=37;
    void fhash(string &s,vector<int>&hash,vector<int>&pk){
        pk[0]=1;
        hash[0]=s[0]-'a'+1;
        for(int i=1;i<s.size();i++){
            hash[i]=(p*hash[i-1]+(s[i]-'a'+1))%mod;
            pk[i]=p*pk[i-1]%mod;
        }
    }

    int val(int l,int r,vector<int>&hash,vector<int>&pk){
        if(l==0) return hash[r];
        return (hash[r]-1LL*hash[l-1]*pk[r-l+1]%mod+mod)%mod;
    }

    int deleteString(string s) {
        int n=s.size(),ans=0;
        int i=n-2;
        vector<int>hash(n),pk(n);
        fhash(s,hash,pk);
        vector<int>dp(n+1); dp[n]=0; dp[n-1]=1;
        while(i>=0){
            dp[i]=1;
            for(int j=i+1;2*j-i<=n;j++){
                if(val(i,j-1,hash,pk)==val(j,2*j-i-1,hash,pk)){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            i--;
        }
        return dp[0];
    }
};
