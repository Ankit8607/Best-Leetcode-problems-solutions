// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int mn=-1,mx=-1,last=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                mn=-1; mx=-1; last=i;
            }
            if(nums[i]==minK) mn=i;
            if(nums[i]==maxK) mx=i;
            if(mn!=-1 and mx!=-1) ans+=min(mx,mn)-last;
        }
        return ans;
    }
};


// In python 

// class Solution:
//     def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
//         ans,mn,mx,last=0,-1,-1,-1
//         for i in range(0,len(nums)):
//             if nums[i]<minK or nums[i]>maxK:
//                 mn=-1
//                 mx=-1
//                 last=i 
//             if nums[i]==minK:
//                 mn=i 
//             if nums[i]==maxK:
//                 mx=i 
//             if mn!=-1 and mx!=-1:
//                 ans+=min(mx,mn)-last 
//         return ans 


// In javascript

// /**
//  * @param {number[]} nums
//  * @param {number} minK
//  * @param {number} maxK
//  * @return {number}
//  */
// var countSubarrays = function(nums, minK, maxK) {
//     let ans=0;
//     let mn=-1,mx=-1,last=-1;
//     for(let i=0;i<nums.length;i++){
//         if(nums[i]<minK || nums[i]>maxK){
//             mn=-1; mx=-1; last=i;
//         }
//         if(nums[i]==minK) mn=i;
//         if(nums[i]==maxK) mx=i;
//         if(mn!=-1 && mx!=-1) ans+=Math.min(mx,mn)-last;
//     }
//     return ans;
// };
