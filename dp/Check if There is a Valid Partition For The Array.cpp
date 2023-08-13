// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int i=1,n=nums.size();
        vector<int>dp(n,0);
        while(i<n){
            if(nums[i]==nums[i-1] and (i>1?dp[i-2]:1)) dp[i]=1;
            else if(i>=2 and nums[i]==nums[i-1] and nums[i]==nums[i-2] and (i>2?dp[i-3]:1)) dp[i]=1;
            else if(nums[i]-nums[i-1]==1 and i>1 and nums[i-1]-nums[i-2]==1 and (i>2 ? dp[i-3] : 1)) dp[i]=1;
            i++;
        }
        return dp[n-1];
    }
};
