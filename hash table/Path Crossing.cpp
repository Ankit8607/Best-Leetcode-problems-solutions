// https://leetcode.com/problems/path-crossing/description/?envType=daily-question&envId=2023-12-23

class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,int>mp;
        mp[{0,0}]=1;
        int k=0,j=0;
        for(auto i:path){
            if(i=='N')j++;
            else if(i=='S')j--;
            else if(i=='E') k++;
            else k--;
            if(mp[{k,j}]) return 1;
            else mp[{k,j}]=1;
        }
        return false;
    }
};
