// https://leetcode.com/problems/subsets/?envType=daily-question&envId=2024-05-21

class Solution {
public:

    void rec(int level, vector<int>&nums,vector<int>&t,vector<vector<int>>&ans){
        if(level==nums.size()){
            ans.push_back(t);
            return;
        }

        rec(level+1,nums,t,ans);
        t.push_back(nums[level]);
        rec(level+1,nums,t,ans);
        t.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>t;
        rec(0,nums,t,ans);
        return ans;
    }
};


// In python

// class Solution:
//     def subsets(self, nums: List[int]) -> List[List[int]]:
//         def rec(level,t,ans):
//             if level==len(nums):
//                 ans.append(t.copy())
//                 print(ans)
//                 return

//             rec(level+1,t,ans)
//             t.append(nums[level])
//             rec(level+1,t,ans)
//             t.pop()
        
//         ans,t=[],[]
//         rec(0,t,ans)
//         return ans


// In javascript

// /**
//  * @param {number[]} nums
//  * @return {number[][]}
//  */
// var subsets = function(nums) {
//     let ans=[],t=[];
//     rec(0,nums,t,ans);
//     return ans;
// };

// var rec=function(level, nums,t,ans){
//     if(level==nums.length){
//         ans.push([...t]);
//         console.log(ans);
//         return;
//     }
//     rec(level+1,nums,t,ans);
//     t.push(nums[level]);
//     rec(level+1,nums,t,ans);
//     t.pop();
// }
