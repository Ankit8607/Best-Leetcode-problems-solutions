// https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:

    bool check(int mid,vector<int>&nums,int &k){
        int cnt=1,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mid){
                cnt++;
                sum=nums[i];
            }
        }
        return cnt<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size(),sum=0;
        for(auto i:nums) sum+=i;
        int lo=*max_element(nums.begin(),nums.end()),hi=sum,ans=sum;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(check(mid,nums,k)){
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;
        }
        return ans;
    }
};
