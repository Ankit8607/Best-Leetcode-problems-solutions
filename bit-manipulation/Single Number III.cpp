// https://leetcode.com/problems/single-number-iii/description/?envType=daily-question&envId=2024-05-31

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(auto i:nums) x^=i;
        int set_bit=x & ~(1LL*x-1),a=0,b=0;
        for(auto i:nums)
            if(i&set_bit) a^=i;
            else b^=i;
        return {a,b};
    }
};


// In python

// class Solution:
//     def singleNumber(self, nums: List[int]) -> List[int]:
//         x=0
//         for i in nums: x^=i
//         set_bit,a,b = x & ~(x-1),0,0
//         for i in nums:
//             if i&set_bit: a^=i
//             else: b^=i
//         return {a,b}


// In javascript

// /**
//  * @param {number[]} nums
//  * @return {number[]}
//  */
// var singleNumber = function(nums) {
//     let x=0;
//     for(let i of nums) x^=i;
//     let set_bit= Number(BigInt(x) & ~((BigInt(x) - 1n)));
//     var a=0,b=0;
//     for(let i of nums)
//         if(i&set_bit) a^=i;
//         else b^=i;
//     return [a,b];
// };
