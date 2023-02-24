// https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/description/

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums)  {
        int ans=1e9,cnt=0,n=nums.size();
        for(int i=1; i<nums.size(); i+=2){
            if(i==n-1){
                if(nums[i-1]<=nums[i]) cnt+=nums[i]-nums[i-1]+1;
            }
            else{
                int mn=min(nums[i-1],nums[i+1]);
                if(mn<=nums[i]) cnt+=nums[i]-mn+1;
            }
        }
        ans=min(ans,cnt);
        cnt=0;
        if(n>1 and nums[0]>=nums[1]) cnt=nums[0]-nums[1]+1;
        for(int i=2; i<nums.size(); i+=2){
            if(i==n-1){
                if(nums[i-1]<=nums[i]) cnt+=nums[i]-nums[i-1]+1;
            }
            else{
                int mn=min(nums[i-1],nums[i+1]);
                if(mn<=nums[i]) cnt+=nums[i]-mn+1;
            }
        }
        return min(ans,cnt);
    }

};
