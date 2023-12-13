// https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2023-12-13

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<int>row(n,0),col(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i]+=mat[i][j];
                col[j]+=mat[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    if(row[i]==1 and col[j]==1) ans++;
                }
            }
        }
        return ans;
    }
};
