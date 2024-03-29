// https://leetcode.com/problems/sort-array-by-parity/?envType=daily-question&envId=2023-09-29

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=n-1;
        while(l<r){
            if(nums[l]%2==0) l++;
            else if(nums[r]%2==1) r--;
            else swap(nums[l],nums[r]);
        }
        return nums;
    }
};
