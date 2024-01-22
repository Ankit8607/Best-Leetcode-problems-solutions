// https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-01-22

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>arr(nums.size(),0);
        for(int i=0;i<nums.size();i++) arr[nums[i]-1]++;
        vector<int>ans(2);
        for(int i=0;i<arr.size();i++) 
            if(arr[i]==2) ans[0]=i+1;
            else if(arr[i]==0) ans[1]=i+1;
        return ans;
    }
};
