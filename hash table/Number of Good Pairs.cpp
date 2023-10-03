// https://leetcode.com/problems/number-of-good-pairs/?envType=daily-question&envId=2023-10-03

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums) mp[i]++;
        int ans=0;
        for(auto i:mp){
            int t=i.second;
            ans+=(t*(t-1))/2;
        }
        return ans;
    }
};
