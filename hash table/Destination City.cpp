// https://leetcode.com/problems/destination-city/description/?envType=daily-question&envId=2023-12-15

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string>mp;
        for(auto i:paths) mp[i[0]]=i[1];
        string start=paths[0][1];
        while(mp.count(start)){
            start=mp[start];
        }
        return start;
    }
};
