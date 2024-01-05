// https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=daily-question&envId=2024-01-05

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        for(auto i: nums){
            if(ans.back()<i) ans.push_back(i);
            else{
                auto it=lower_bound(ans.begin(),ans.end(),i)-ans.begin();
                ans[it]=i;
            }
        }
        return ans.size();
    }
};
