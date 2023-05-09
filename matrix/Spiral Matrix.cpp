// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int n=mat.size(),m=mat[0].size();
        int i=0,j=0,dir=0,tot=n*m;
        int left=0,right=m-1,up=0,down=n-1;
        while(ans.size()<n*m){
            if(dir==0){
                for(int i=left;i<=right;i++)
                    ans.push_back(mat[up][i]);
                up++;
                dir=1;
            }
            else if(dir==1){
                for(int i=up;i<=down;i++)
                    ans.push_back(mat[i][right]);
                right--;
                dir=2;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--)
                    ans.push_back(mat[down][i]);
                down--;
                dir=3;
            }
            else{
                for(int i=down;i>=up;i--)
                    ans.push_back(mat[i][left]);
                left++;
                dir=0;
            }
        }
        return ans;
    }
};
