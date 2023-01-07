// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

class Solution {
public:

    bool check(int mid,vector<int>&nums,int k){
        int cnt=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>mid) cnt+=ceil(1.0*nums[i]/mid)-1;
        }
        return cnt<=k;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int l=1,r=*max_element(nums.begin(),nums.end()),ans;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,nums,maxOperations)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
