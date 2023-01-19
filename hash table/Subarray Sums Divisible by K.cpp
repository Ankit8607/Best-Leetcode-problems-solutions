//https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=0,sum=0;
        mp[0]++;
        for(auto &i:nums){
            sum+=i;
            if(sum<0) sum=(sum%k+k)%k;
            ans+=mp[sum%k];
            mp[sum%k]++;
        }
        return ans;
    }
};
