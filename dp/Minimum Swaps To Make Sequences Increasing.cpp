// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

class Solution {
public:
    int dp[100100][2];
    int rec(int level,int last,vector<int>&nums1,vector<int> &nums2){
        if(level==nums1.size()) return 0;

        if(dp[level][last]!=-1) return dp[level][last];

        int ans=1e9;
        if(level==0) ans=min(rec(level+1,0,nums1,nums2),1+rec(level+1,1,nums1,nums2));
        else{
            if(last==0){
                if(nums1[level]>nums1[level-1] and nums2[level]>nums2[level-1]) ans=min(ans,rec(level+1,0,nums1,nums2));
                if(nums1[level]>nums2[level-1] and nums2[level]>nums1[level-1]) ans=min(ans,1+rec(level+1,1,nums1,nums2));
            }
            else{
                if(nums1[level]>nums2[level-1] and nums2[level]>nums1[level-1]) ans=min(ans,rec(level+1,0,nums1,nums2));
                if(nums1[level]>nums1[level-1] and nums2[level]>nums2[level-1]) ans=min(ans,1+rec(level+1,1,nums1,nums2));
            }
        }
        return dp[level][last]=ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,nums1,nums2);
    }
};
