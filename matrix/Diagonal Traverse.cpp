// https://leetcode.com/problems/diagonal-traverse/description/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int dir=1;
        int n=mat.size();
        int m=mat[0].size();
        int i=0,j=0;
        while(i<n and j<m){
            ans.push_back(mat[i][j]);
            if(dir){
                if(i==0){
                    if(j!=m-1) j++,dir=0;
                    else i++,dir=0;
                }
                else if(j==m-1) i++,dir=0;
                else i--,j++;
            }
            else{
                if(j==0){
                    if(i!=n-1) i++,dir=1;
                    else j++,dir=1;
                }
                else if(i==n-1) j++,dir=1;
                else i++,j--;
            }
        }
        return ans;
    }
};
