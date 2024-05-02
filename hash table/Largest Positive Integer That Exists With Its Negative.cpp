// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=daily-question&envId=2024-05-02

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans=-1;
        map<int,int>mp;
        for(auto i:nums) mp[i]++;
        for(auto i:nums){
            if(i>ans and mp[-i]) ans=i;
        }
        return ans;
    }
};
