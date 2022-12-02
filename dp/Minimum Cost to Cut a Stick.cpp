// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

class Solution {
public:
    vector<int>arr;
    int dp[401][401];
    int rec(int l,int r){
        if(r-l<=1) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        int ans=1e9;
        for(int i=l+1;i<r;i++){
            ans=min(ans,arr[r]-arr[l]+rec(l,i)+rec(i,r));
        }

        return dp[l][r]=ans;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));
        arr.push_back(0);
        for(auto &i:cuts){
            arr.push_back(i);
        }
        arr.push_back(n);
        return rec(0,arr.size()-1);
    }
};
