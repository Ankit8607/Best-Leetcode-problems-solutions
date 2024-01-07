// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/?envType=daily-question&envId=2024-01-07

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(),ans=0;
        unordered_map<int,int>mp[n];
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                auto diff=1ll*nums[i]-nums[j];
                if(diff>INT_MAX || diff<INT_MIN) continue;
                int t=mp[j][diff];
                ans+=t;
                mp[i][diff]+=t+1;
            }
        }
        return ans;
    }
};
