// https://leetcode.com/problems/binary-subarrays-with-sum/description/?envType=daily-question&envId=2024-03-14

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0,l=0,r=0,n=nums.size(),ans=0,cnt=0;
        while(l<n){
            while(l<n and sum+nums[l]<=goal){
                sum+=nums[l];
                if(sum==goal) cnt++;
                l++;
            }
            while(r<l and sum==goal){
                ans+=cnt;
                sum-=nums[r];
                if(sum==0) cnt--;
                r++;
            }
            cnt=0;
            if(l==r) l++,r++;
        }
        return ans;
    }
};
