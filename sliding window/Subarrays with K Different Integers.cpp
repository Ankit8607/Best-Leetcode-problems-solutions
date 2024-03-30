// https://leetcode.com/problems/subarrays-with-k-different-integers/description/?envType=daily-question&envId=2024-03-30

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int left=-1,l=0,r=0,ans=0,n=nums.size();
        map<int,int>mp;
        while(r<n){
            mp[nums[r++]]++;
            while(mp.size()>k || mp[nums[l]]>1){
                if(mp.size()>k) left=l;
                if(mp[nums[l]]>1) mp[nums[l]]--;
                else mp.erase(nums[l]);
                l++;
            }
            if(mp.size()==k) ans+=l-left;
        }
        return ans;
    }
};



// In python 

// class Solution:
//     def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
//         left,l,r,ans,n=-1,0,0,0,len(nums)
//         mp={}
//         while r<n:
//             if nums[r] in mp:
//                 mp[nums[r]]+=1
//             else:
//                 mp[nums[r]]=1
//             while len(mp)>k or mp[nums[l]]>1:
//                 if len(mp)>k:
//                     left=l
//                 if mp[nums[l]]>1:
//                     mp[nums[l]]-=1
//                 else:
//                     mp.pop(nums[l])
//                 l+=1
//             if len(mp)==k:
//                 ans+=l-left
//             r+=1
//         return ans


// In javascript


// /**
//  * @param {number[]} nums
//  * @param {number} k
//  * @return {number}
//  */
// var subarraysWithKDistinct = function(nums, k) {
//     let left=-1,l=0,r=0,ans=0,n=nums.length;
//     let mp=new Map();
//     while(r<n){
//         if(mp.has(nums[r]))
//             mp.set(nums[r],mp.get(nums[r])+1);
//         else mp.set(nums[r],1);
//         while(mp.size>k || mp.get(nums[l])>1){
//             if(mp.size>k) left=l;
//             if(mp.get(nums[l])>1) mp.set(nums[l],mp.get(nums[l])-1);
//             else mp.delete(nums[l]);
//             l++;
//         }
//         if(mp.size==k) ans+=l-left;
//         r++;
//     }
//     return ans;
// };
