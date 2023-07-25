// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int ans=0,l=1,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]>arr[mid-1]){
                l=mid+1;
                ans=mid;
            }
            else r=mid-1;
        }
        return ans;
    }
};
