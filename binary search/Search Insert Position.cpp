// https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int t=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        int i=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(t!=i) return i;
        return t;
    }
};
