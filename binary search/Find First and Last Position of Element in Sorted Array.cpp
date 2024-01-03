// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/?envType=daily-question&envId=2023-10-09

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { 
        int it=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int it2=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(it==nums.size() || nums[it]!=target) return {-1,-1};
        return {it,it2-1};
    }
};
