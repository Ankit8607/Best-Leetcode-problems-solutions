// https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n= nums.size();
        int dp[n],last[n];
        dp[n-1]=1;
        last[n-1]=n;
        sort(nums.begin(),nums.end()); 
        int res=1;
        for(int i=n-2;i>=0;i--){
            dp[i]=1;
            last[i]=n;
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        last[i]=j;
                    }
                }
            }
            res=max(res,dp[i]);
        }
        vector<int>ans;
        int i=0;
        while(i<n){
            if(dp[i]==res){ 
                ans.push_back(nums[i]);
                res--;
                i=last[i];
            }
            else i++;
        }
        return ans;
    }
};
