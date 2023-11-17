// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans =0;
        int l=0,r=nums.size()-1; 
        while(l<r){
            ans=max(ans,nums[r]+nums[l]);
            l++; r--;
        }
        return ans;
    }
};
