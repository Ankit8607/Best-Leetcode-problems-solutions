// https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    unordered_map<int,int>mp;
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        // int ans=1,cnt=1;
        // sort(nums.begin(),nums.end());
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i]==nums[i-1]) continue;
        //     if(nums[i]-nums[i-1]==1) cnt++;
        //     else cnt=1;
        //     ans=max(ans,cnt);
        // }
        // return ans;
        int ans=1;
        for(auto i: nums) mp[i]=1;
        for(auto i:nums){
            if(!mp.count(i-1)){
                int t=i+1,cnt=1;
                while(mp.count(t++)) cnt++;
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};
