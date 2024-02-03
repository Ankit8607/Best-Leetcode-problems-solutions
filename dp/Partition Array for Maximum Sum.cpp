// https://leetcode.com/problems/partition-array-for-maximum-sum/description/?envType=daily-question&envId=2024-02-03

class Solution {
public:
    int dp[500][500];
    int rec(int level,int taken,int k,vector<int>& arr,int mx){
        if(level==arr.size()) return 0;

        if(dp[level][taken]!=-1) return dp[level][taken];

        int ans=arr[level]+rec(level+1,1,k,arr,arr[level]);
        if(taken<k){
            if(arr[level]>mx){
                ans=max(ans,(taken+1)*arr[level]-taken*mx+rec(level+1,taken+1,k,arr,arr[level]));
            }
            else ans=max(ans,mx+rec(level+1,taken+1,k,arr,mx));
        }

        return dp[level][taken]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,k,arr,0);
    }
};
