// https://leetcode.com/problems/contiguous-array/?envType=daily-question&envId=2024-03-16

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int sum=0,ans=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]) sum++;
            else sum--;
            if(mp.count(sum)) ans=max(ans,i-mp[sum]);
            if(!mp.count(sum)) mp[sum]=i;
        }
        return ans;
    }
};

// In Python 

// class Solution:
//     def findMaxLength(self, nums: List[int]) -> int:
//         map = {0:-1}
//         sum,ans=0,0
//         for i in range(0,len(nums)):
//             if nums[i]: sum+=1
//             else: 
//                 sum-=1
//             if sum in map:
//                 ans=max(ans,i-map[sum])
//             else: 
//                 map[sum]=i
//         return ans


  
  
// In JavaScript

// /**
//  * @param {number[]} nums
//  * @return {number}
//  */
// var findMaxLength = function(nums) {
//     let mp = new Map([[0,-1]]);
//     let sum=0,ans=0;
//     for(let i=0;i<nums.length;i++){
//         if(nums[i]) sum++;
//         else sum--;
//         if(mp.has(sum)) ans=Math.max(ans,i-mp.get(sum));
//         else mp.set(sum,i);
//     }
//     return ans;
// };

