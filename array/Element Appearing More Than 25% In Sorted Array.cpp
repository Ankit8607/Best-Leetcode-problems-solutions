// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/?envType=daily-question&envId=2023-12-11

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto i:arr) mp[i]++;
        for(auto i:mp){
            if(i.second>(arr.size()/4)) return i.first;
        }
        return -1;
    }
};
