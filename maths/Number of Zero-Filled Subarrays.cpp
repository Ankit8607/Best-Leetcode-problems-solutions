// https://leetcode.com/problems/number-of-zero-filled-subarrays/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0,i=0,n=nums.size();
        while(i<n){
            int cnt=0;
            while(i<n and nums[i]==0) i++,cnt++;
            ans+=1LL*cnt*(cnt+1)/2;
            i++;
        }
        return ans;
    }
};
