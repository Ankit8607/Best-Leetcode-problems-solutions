// https://leetcode.com/problems/maximum-matrix-sum/description/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mn=1e9,cnt=0,flag=0;
        long long int ans=0;
        for(auto &i:matrix){
            for(int &j:i){
                if(j<0){
                    j=abs(j);
                    cnt++;
                    ans+=j;
                }
                else if(j==0) flag=1;
                else ans+=j;
                mn=min(mn,j);
            }
        }
        if(cnt%2==0 || flag) return ans;
        return ans-2*mn;
    }
};
