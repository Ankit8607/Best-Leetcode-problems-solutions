// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0,hi=n-1,ans=0;
        while(lo<=hi){
            int mid=(lo+hi)/1;
            if(nums[0]>nums[mid]){
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;
        }
        auto it=lower_bound(nums.begin()+ans,nums.end(),target)-nums.begin();
        if(it!=n and nums[it]==target) return it;
        if(ans==0) return -1;
        it=lower_bound(nums.begin(),nums.begin()+ans,target)-nums.begin();
        if(nums[it]==target) return it;
        return -1;
    }
};
