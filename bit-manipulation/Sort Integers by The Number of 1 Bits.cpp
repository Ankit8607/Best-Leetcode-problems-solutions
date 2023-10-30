// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/?envType=daily-question&envId=2023-10-30

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>v;
        for(auto i:arr){
            int cnt=0;
            for(int j=0;j<15;j++){
                if((1<<j)&i) cnt++;
            }
            v.push_back({cnt,i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<arr.size();i++) arr[i]=v[i].second;
        return arr;
    }
};
