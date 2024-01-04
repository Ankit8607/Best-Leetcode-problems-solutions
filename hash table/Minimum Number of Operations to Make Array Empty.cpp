// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/?envType=daily-question&envId=2024-01-04

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums) mp[i]++;
        int ans=0;
        for(auto i:mp){
            int t=i.second;
            if(t%3==0) ans+=t/3;
            else if(t%2==0) ans+=2*(t/6)+(t-(t/6)*6)/2;
            else{
                ans++;
                t-=3;
                if(t<0) return -1;
                if(t%3==0) ans+=t/3;
                else if(t%2==0) ans+=2*(t/6)+(t-(t/6)*6)/2;
                else return -1;
            }
        }
        return ans;
    }
};
