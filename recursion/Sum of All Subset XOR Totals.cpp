// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2024-05-20


class Solution {
public:

    int rec(int level, int x, vector<int>&nums){
        if(level==nums.size()) return x;

        int ans=rec(level+1,x,nums)+rec(level+1,x^nums[level],nums);

        return ans;
    }

    int subsetXORSum(vector<int>& nums) {
        return rec(0,0,nums);
    }
};


// In python

// class Solution:
//     def subsetXORSum(self, nums: List[int]) -> int:
//         def rec(level, x):
//             if level==len(nums): return x
//             return rec(level+1,x)+rec(level+1,x^nums[level])
//         return rec(0,0)


// In javascript

// /**
//  * @param {number[]} nums
//  * @return {number}
//  */
// var subsetXORSum = function(nums) {
//     return rec(0,0,nums);
// };

// let rec = (level, x,nums)=>{
//     if(level==nums.length) return x;
//     return rec(level+1,x,nums)+rec(level+1,x^nums[level],nums);
// };
