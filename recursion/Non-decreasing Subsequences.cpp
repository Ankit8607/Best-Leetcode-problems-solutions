// https://leetcode.com/problems/non-decreasing-subsequences/

class Solution {
public:
    set<vector<int>>ans;
    void rec(int level, vector<int> &v, vector<int> &nums){
        if(level==nums.size()){
            if(v.size()>1) ans.insert(v);
            return;
        }
        rec(level+1,v,nums);
        if(v.size()==0){
            v.push_back(nums[level]);
            rec(level+1,v,nums);
            v.pop_back();
        }
        else{
            if(nums[level]>=v.back()){
                v.push_back(nums[level]);
                rec(level+1,v,nums);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>v;
        rec(0,v,nums);
        vector<vector<int>>res;
        for(auto &i:ans) res.push_back(i);
        return res;
    }
};
