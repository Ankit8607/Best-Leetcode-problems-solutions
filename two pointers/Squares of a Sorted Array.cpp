// https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &i:nums) i=i*i;
        vector<int>arr;
        int l=0,r=nums.size()-1;
        while(l<=r){
            if(nums[l]>nums[r]) arr.push_back(nums[l++]);
            else arr.push_back(nums[r--]);
        }
        reverse(arr.begin(),arr.end());
        return arr;
    }
};
