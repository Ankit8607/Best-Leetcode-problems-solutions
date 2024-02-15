// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/?envType=daily-question&envId=2024-02-15

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans=-1,sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>1 and sum>nums[i]) ans=sum+nums[i];
            sum+=nums[i];
        }
        return ans;
    }
};
