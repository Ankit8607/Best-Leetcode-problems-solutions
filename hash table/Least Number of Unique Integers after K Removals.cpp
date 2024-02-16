// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;
        for(auto i:arr) mp[i]++;
        vector<int>nums;
        for(auto i:mp) nums.push_back(i.second);
        sort(nums.begin(),nums.end());
        int i=0;
        while(k and i<nums.size()){
            if(nums[i]<=k) k-=nums[i++];
            else break;
        }
        return nums.size()-i;
    }
};
