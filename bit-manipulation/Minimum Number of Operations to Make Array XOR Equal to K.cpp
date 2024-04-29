// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/?envType=daily-question&envId=2024-04-29

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0,cnt=0;
        for(auto i:nums) ans^=i;
        ans^=k;
        while(ans){
            if(ans&1) cnt++;
            ans>>=1;
        }
        return cnt;
    }
};


// In python

// class Solution:
//     def minOperations(self, nums: List[int], k: int) -> int:
//         ans,cnt=0,0
//         for i in nums: ans^=i
//         ans^=k
//         while ans:
//             if ans&1 : cnt+=1
//             ans>>=1
//         return cnt

  
// In javascript

// /**
//  * @param {number[]} nums
//  * @param {number} k
//  * @return {number}
//  */
// var minOperations = function(nums, k) {
//     let ans=0,cnt=0;
//     for(let i of nums) ans^=i;
//     ans^=k;
//     while(ans){
//         if(ans&1) cnt++;
//         ans>>=1;
//     }
//     return cnt;
// };
