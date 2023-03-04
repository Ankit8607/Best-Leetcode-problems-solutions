// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int mn=-1,mx=-1,last=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                mn=-1; mx=-1; last=i;
            }
            if(nums[i]==minK) mn=i;
            if(nums[i]==maxK) mx=i;
            if(mn!=-1 and mx!=-1) ans+=min(mx,mn)-last;
        }
        return ans;
    }
};
