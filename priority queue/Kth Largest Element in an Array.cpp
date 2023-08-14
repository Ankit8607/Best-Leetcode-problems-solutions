// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int,greater<int>>mt;
        for(auto i: nums){
            mt.insert(i);
            if(mt.size()>k) mt.erase(prev(mt.end()));
        }
        return *mt.rbegin();
    }
};
