// https://leetcode.com/problems/permutations/description/

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<vector<int>>ans;
//         do{
//             ans.push_back(nums);
//         }while(next_permutation(nums.begin(),nums.end()));
//         return ans;
//     }
// };

class Solution {
public:

    void rec(int level,int n,vector<int>&nums, vector<vector<int>>&ans){
        if(level==n){
            ans.push_back(nums);
            return;
        }

        rec(level+1,n,nums,ans);
        for(int i=level+1;i<n;i++){
            swap(nums[i],nums[level]);
            rec(level+1,n,nums,ans);
            swap(nums[i],nums[level]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        rec(0,nums.size(),nums,ans);
        return ans;
    }
};
