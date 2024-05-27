// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/?envType=daily-question&envId=2024-05-27

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int last=-1,n=nums.size();
        map<int,int>mp;
        for(auto i:nums) mp[i]++;
        for(auto i:mp){
            if(i.first>=n and n>last) return n;
            last=i.first;
            n-=i.second;
        }
        return -1;
    }
};
