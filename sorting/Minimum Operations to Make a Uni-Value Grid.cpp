// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        for(auto &i:grid){
            for(auto &j:i){
                v.push_back(j);
            }
        }
        sort(v.begin(), v.end());
        int n=v.size();
        int med=v[n/2];
        int ans=0;
        for(int &i:v){
            if((i+((med-i)/x)*x)!=med) return -1;
            ans+=abs(med-i)/x;
        }
        return ans;
    }
};
