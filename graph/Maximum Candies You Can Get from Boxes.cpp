// https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/

class Solution{
public:
    int ans=0;
    unordered_map<int,bool>contains;

    void rec(int box,vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes){
        contains[box]=1;
        if(!status[box]) return;
        contains[box]=0;
        ans+=candies[box];
        for(auto &i:keys[box]){
            status[i]=1;
            if(contains[i]==1) rec(i,status,candies,keys,containedBoxes);
        }
        for(int &i:containedBoxes[box]){
            rec(i,status,candies,keys,containedBoxes);
        }
    }

    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        for(int &i:initialBoxes){
            rec(i,status, candies, keys,containedBoxes);
        }
        return ans;
    }
};
