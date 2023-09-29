// https://leetcode.com/problems/monotonic-array/?envType=daily-question&envId=2023-09-29

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size(),ans=1;
        for(int i=1;i<n;i++) 
            if(nums[i]>nums[i-1]) ans=0;
        if(ans) return ans;
        ans=1;
        for(int i=1;i<n;i++) 
            if(nums[i]<nums[i-1]) ans=0;
        return ans;
    }
};
