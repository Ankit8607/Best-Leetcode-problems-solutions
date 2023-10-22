// https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/?envType=daily-question&envId=2023-10-22

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans=nums[k],mn=nums[k];
        int i=k-1,j=k+1,n=nums.size();
        while(i>=0 || j<n){
            if(i>=0 and j<n){
                if(nums[i]>nums[j]) mn=min(mn,nums[i]),i--;
                else mn=min(mn,nums[j]),j++;
            }
            else if(i<0) mn=min(mn,nums[j]),j++;
            else mn=min(mn,nums[i]),i--;
            ans=max(ans,(j-i-1)*mn);
        }
        return ans;
    }
};
