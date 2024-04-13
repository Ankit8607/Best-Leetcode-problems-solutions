// https://leetcode.com/problems/maximal-rectangle/description/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size(),m=mat[0].size(); 
        vector<vector<int>> row(n,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i][j+1]=row[i][j]+(mat[i][j]-'0');
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            for(int j=i;j<=m;j++){
                int sum=0,t=j-i+1;
                for(int k=0;k<n;k++){
                    if(row[k][j]-row[k][i-1]<t) sum=0;
                    else sum++;
                    ans=max(ans,(j-i+1)*sum);
                }
            }
        }
        return ans;
    }
};
