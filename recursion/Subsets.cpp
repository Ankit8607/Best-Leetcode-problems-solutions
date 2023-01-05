// https://leetcode.com/problems/subsets/

class Solution {
public:
    void rec(int level,vector<int>&nums,vector<vector<int>>&ans,vector<int>&tmp)   {
        if(level==nums.size()) {
            ans.push_back(tmp); 
            return;
        }

        rec(level+1,nums,ans,tmp);
        tmp.push_back(nums[level]);
        rec(level+1,nums,ans,tmp);
        tmp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tmp;
        rec(0,nums,ans,tmp);
        return ans;
    }
};
