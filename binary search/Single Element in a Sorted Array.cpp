// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans=0;
        for(auto &i:nums) ans^=i;
        return ans;
    }
};
