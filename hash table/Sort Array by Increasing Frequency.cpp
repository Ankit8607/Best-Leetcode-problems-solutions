// https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=daily-question&envId=2024-07-23

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int,int>>v;
        map<int,int>mp;
        for(auto i:nums) mp[i]++;
        for(auto i:mp) v.push_back({i.first,i.second});
        sort(nums.begin(),nums.end(),[&mp](int &a,int &b){
            if(mp[a]==mp[b]) return a>b;
            return mp[a]<mp[b];
        });
        return nums;
    }
};
