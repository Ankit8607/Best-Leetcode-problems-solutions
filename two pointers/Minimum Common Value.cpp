// https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,n=nums1.size(),m=nums2.size();
        while(i<n and j<m){ 
            if(nums1[i]==nums2[j]) return nums1[i];
            if(nums1[i]>nums2[j]) j++; 
            else i++;
        }
        return -1; 
    }
};
