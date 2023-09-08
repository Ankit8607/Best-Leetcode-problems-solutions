// https://leetcode.com/problems/pascals-triangle/?envType=daily-question&envId=2023-09-08

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        int t=0;
        while(t<numRows){
            ans[t].push_back(1);
            for(int i=1;i<t;i++) ans[t].push_back(ans[t-1][i-1]+ans[t-1][i]);
            if(t) ans[t].push_back(1);
            t++;
        }
        return ans;
    }
};
