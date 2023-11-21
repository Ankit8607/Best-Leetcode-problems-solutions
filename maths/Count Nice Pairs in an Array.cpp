// https://leetcode.com/problems/count-nice-pairs-in-an-array/description/?envType=daily-question&envId=2023-11-21

class Solution {
public:

    int rev(int n){
        int ans=0;
        while(n){
            ans=ans*10+n%10;
            n/=10;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums) mp[i-rev(i)]++;
        int ans=0,mod=1e9+7;
        for(auto i:mp) ans=(ans+(1LL*i.second*(i.second-1))/2%mod)%mod;
        return ans;
    }
};
