// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int pre[n+1],suf[n+1];
        pre[0]=1;
        for(int i=0;i<n;i++) pre[i+1]=pre[i]*nums[i];
        suf[n]=1;
        for(int i=n-1;i>=0;i--) suf[i]=suf[i+1]*nums[i];
        vector<int>ans(n);
        for(int i=0;i<n;i++) ans[i]=pre[i]*suf[i+1];
        return ans;
    }
};
