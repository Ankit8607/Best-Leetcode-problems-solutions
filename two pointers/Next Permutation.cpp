// https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0){
            if(nums[i]<nums[i+1]) break;
            i--;
        }
        if(i<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        auto it=lower_bound(nums.begin()+i+1,nums.end(),nums[i],greater<int>())-nums.begin();
        swap(nums[i],nums[it-1]);
        reverse(nums.begin()+i+1,nums.end());
    }
};
