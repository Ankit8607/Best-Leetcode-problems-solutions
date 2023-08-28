// https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/

class Solution {
public:
    int rec(int level,vector<vector<pair<int,int>>>&dp, int mn,int x,int &n,vector<vector<int>>&memo){
        if(level==dp.size()){
            if(x==0) return 0;
            return 1e9;
        }

        if(memo[level][x]!=-1) return memo[level][x];

        int ans=1e9,k=dp.size();
        for(auto i:dp[level]){
            ans=min(ans,n/k+((n%k)>level)-i.second+rec(level+1,dp,min(mn,i.second),x^i.first,n,memo));
        return memo[level][x]=ans;
    }

    int minChanges(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1){
            int mx=0;
            for(auto i:nums) if(i!=0) mx++;
            return mx;
        }
        vector<vector<int>>memo(k,vector<int>((1<<11),-1));
        vector<vector<pair<int,int>>>dp(k);
        int res=0,mn=1e9;
        for(int i=0;i<k;i++){
            map<int,int>mp;
            for(int j=i;j<n;j+=k) mp[nums[j]]++;
            int mx=0;
            for(auto j:mp) dp[i].push_back({j.first,j.second}),mx=max(mx,j.second);
            res+=n/k+((n%k)>i)-mx;
            mn=min(mn,mx);
        }
        int t=rec(0,dp,1e9,0,n,memo);
        cout<<t<<endl;
        return min(res+mn,t);
    }
};
