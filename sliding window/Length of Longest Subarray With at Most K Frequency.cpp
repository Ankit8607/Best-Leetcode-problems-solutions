// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2024-03-28

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size(),ans=1;
        map<int,int>mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp[nums[r]]>k){
                mp[nums[l]]--;
                l++;
            }
            r++;
            ans=max(ans,r-l);
        }
        return ans;
    }
};


// In python

// class Solution:
//     def maxSubarrayLength(self, nums: List[int], k: int) -> int:
//         l,r,n,ans=0,0,len(nums),1
//         mp={}
//         while r<n:
//             if nums[r] in mp:
//                 mp[nums[r]]+=1
//             else:
//                 mp[nums[r]]=1
//             while mp[nums[r]]>k:
//                 mp[nums[l]]-=1
//                 l+=1
//             r+=1
//             ans=max(ans,r-l)
//         return ans


// In javascript

// /**
//  * @param {number[]} nums
//  * @param {number} k
//  * @return {number}
//  */
// var maxSubarrayLength = function(nums, k) {
//     let l=0,r=0,n=nums.length,ans=1;
//     let mp=new Map();
//     while(r<n){
//         if(mp.has(nums[r])) mp.set(nums[r],mp.get(nums[r])+1);
//         else mp.set(nums[r],1);
//         while(mp.get(nums[r])>k){
//             mp.set(nums[l],mp.get(nums[l])-1);
//             l++;
//         }
//         r++;
//         ans=Math.max(ans,r-l);
//     }
//     return ans;
// };
