// https://leetcode.com/problems/diagonal-traverse-ii/description/?envType=daily-question&envId=2023-11-22

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            int t=i;
            for(auto j:nums[i]) mp[t++].push_back(j);
        }
        for(auto &i:mp) reverse(i.second.begin(),i.second.end());
        vector<int>ans;
        for(auto i:mp) ans.insert(ans.end(),i.second.begin(),i.second.end());
        return ans;
    }
};
