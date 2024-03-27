// https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=daily-question&envId=2024-03-27

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0,r=0,ans=0,n=nums.size(),mul=1;
        while(l<nums.size()){
            while(r<n and nums[r]*mul<k){
                mul=mul*nums[r];
                r++;
            }
            if(mul<k){
                ans+=r-l;
            }
            if(r>l) mul/=nums[l];
            l++;
            if(l>r) r=l;
        }
        return ans;
    }
};
