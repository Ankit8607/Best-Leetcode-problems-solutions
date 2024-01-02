// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?envType=daily-question&envId=2024-01-02

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(ans.size()<mp[nums[i]]) ans.push_back({nums[i]});
            else ans[mp[nums[i]]-1].push_back(nums[i]);
        }
        return ans;
    }
};
