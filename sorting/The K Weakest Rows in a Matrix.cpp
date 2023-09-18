// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/?envType=daily-question&envId=2023-09-18

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>arr;
        for(int i=0;i<mat.size();i++){
            int cnt=0;
            for(auto j:mat[i]) cnt+=j;
            arr.push_back({cnt,i});
        }
        vector<int>ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<k;i++) ans.push_back(arr[i].second);
        return ans;
    }
};
