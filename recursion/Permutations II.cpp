// https://leetcode.com/problems/permutations-ii/description/

// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
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

        vector<int>vis(30,0);
        rec(level+1,n,nums,ans);
        for(int i=level+1;i<n;i++){
            if(nums[i]==nums[level] || vis[nums[i]+10]) continue;
            vis[nums[i]+10]=1;
            swap(nums[i],nums[level]);
            rec(level+1,n,nums,ans);
            swap(nums[i],nums[level]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        rec(0,nums.size(),nums,ans);
        return ans;
    }
};
