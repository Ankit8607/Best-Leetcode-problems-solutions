// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-15

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp;
        for(auto i:matches){
            mp[i[1]]++;
            if(!mp.count(i[0])) mp[i[0]]=0;
        }
        vector<vector<int>>ans(2);
        for(auto i:mp){
            if(i.second<=1) ans[i.second].push_back(i.first);
        }
        return ans;
    }
};
