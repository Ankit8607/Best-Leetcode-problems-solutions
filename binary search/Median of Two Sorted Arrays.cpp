// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

class Solution     {
public:

    int kthElement(vector<int>&arr1, vector<int>& arr2, int n, int m, int k)
    {
        if(n>m) return kthElement(arr2,arr1,m,n,k);
        
        int low=max(0,k-m),high=min(n,k);
        while(low<=high){
            int mid1=(low+high)/2;
            int mid2=k-mid1;
            
            int l1=mid1==0?INT_MIN:arr1[mid1-1];
            int l2=mid2==0?INT_MIN:arr2[mid2-1];
            
            int r1=mid1==n?INT_MAX:arr1[mid1];
            int r2=mid2==m?INT_MAX:arr2[mid2];
            
            if(l1<=r2 and l2<=r1) return max(l1,l2);
            if(l1>r2) high=mid1-1;
            else low=mid1+1;
        }
        return 1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int k=(n+m)/2;
        double t=kthElement(nums1,nums2,n,m,k+1);
        if((n+m)%2) return t;
        t+=kthElement(nums1,nums2,n,m,k);
        return t/2;
    }
};
