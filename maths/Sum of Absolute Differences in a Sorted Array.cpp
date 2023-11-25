// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/?envType=daily-question&envId=2023-11-25

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum=0,n=nums.size();
        vector<int>ans;
        for(auto i:nums) sum+=i;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]*(2*i-n)+sum);
            sum-=2*nums[i];
        }
        return ans;
    }
};
