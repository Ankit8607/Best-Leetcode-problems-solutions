// https://leetcode.com/problems/sort-an-array/description/

class Solution  {
public:

    void merge(int l,int mid,int r,vector<int>&nums){
        vector<int> arr(r-l+1);
        int k=0,i=l,j=mid+1;
        while(i<=mid and j<=r){
            if(nums[i]<=nums[j]) arr[k++]=nums[i++];
            else arr[k++]=nums[j++];
        }
        while(i<=mid) arr[k++]=nums[i++];
        while(j<=r) arr[k++]=nums[j++];
        for(int t=l;t<=r;t++) nums[t]=arr[t-l];
    }

    void sort(int l,int r,vector<int> &nums){
        if(l>=r) return;
        int mid=(l+r)/2;
        sort(l,mid,nums);
        sort(mid+1,r,nums);
        merge(l,mid,r,nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        sort(0,nums.size()-1,nums);
        return nums;
    }
};
